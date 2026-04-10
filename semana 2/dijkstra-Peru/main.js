// 1. LAS 25 REGIONES (Claves por nombre de Departamento / Capital)
const nodos = {
    "Amazonas": { lat: -6.2317, lng: -77.8690 },
    "Áncash": { lat: -9.5278, lng: -77.5278 },
    "Apurímac": { lat: -13.6339, lng: -72.8814 }, // Capital: Abancay
    "Arequipa": { lat: -16.4090, lng: -71.5375 },
    "Ayacucho": { lat: -13.1588, lng: -74.2239 },
    "Cajamarca": { lat: -7.1638, lng: -78.5003 },
    "Callao": { lat: -12.0566, lng: -77.1284 },
    "Cusco": { lat: -13.5319, lng: -71.9675 },
    "Huancavelica": { lat: -12.7826, lng: -74.9727 },
    "Huánuco": { lat: -9.9306, lng: -76.2422 },
    "Ica": { lat: -14.0678, lng: -75.7286 },
    "Junín": { lat: -12.0651, lng: -75.2049 },
    "La Libertad": { lat: -8.1160, lng: -79.0300 },
    "Lambayeque": { lat: -6.7714, lng: -79.8406 },
    "Lima": { lat: -12.0464, lng: -77.0428 },
    "Loreto": { lat: -3.7491, lng: -73.2538 },
    "Madre de Dios": { lat: -12.5933, lng: -69.1891 },
    "Moquegua": { lat: -17.1983, lng: -70.9357 },
    "Pasco": { lat: -10.6675, lng: -76.2567 },
    "Piura": { lat: -5.1945, lng: -80.6328 },
    "Puno": { lat: -15.8402, lng: -70.0219 },
    "San Martín": { lat: -6.4850, lng: -76.3595 },
    "Tacna": { lat: -18.0117, lng: -70.2536 },
    "Tumbes": { lat: -3.5669, lng: -80.4515 },
    "Ucayali": { lat: -8.3791, lng: -74.5539 }
};

const conexiones = [
    ["Tumbes", "Piura"], ["Piura", "Lambayeque"], ["Lambayeque", "Cajamarca"],
    ["Lambayeque", "La Libertad"], ["Cajamarca", "Amazonas"], ["Cajamarca", "La Libertad"],
    ["La Libertad", "Áncash"], ["La Libertad", "San Martín"], ["Amazonas", "San Martín"],
    ["San Martín", "Loreto"], ["San Martín", "Huánuco"], ["Áncash", "Lima"],
    ["Áncash", "Huánuco"], ["Huánuco", "Pasco"], ["Huánuco", "Ucayali"],
    ["Pasco", "Junín"], ["Junín", "Lima"], ["Junín", "Ucayali"],
    ["Junín", "Huancavelica"], ["Junín", "Cusco"], ["Lima", "Callao"],
    ["Lima", "Ica"], ["Ica", "Huancavelica"], ["Ica", "Ayacucho"],
    ["Ica", "Arequipa"], ["Huancavelica", "Ayacucho"], ["Ayacucho", "Apurímac"],
    ["Apurímac", "Cusco"], ["Cusco", "Madre de Dios"], ["Cusco", "Puno"], 
    ["Arequipa", "Moquegua"], ["Arequipa", "Puno"], ["Moquegua", "Tacna"], ["Moquegua", "Puno"]
];

let map;
let polyline = null;

function initMap() {
    map = new google.maps.Map(document.getElementById("map"), {
        center: { lat: -9.19, lng: -75.01 },
        zoom: 6,
        styles: [{ featureType: "poi", elementType: "labels", stylers: [{ visibility: "off" }] }]
    });

    const selectOrigen = document.getElementById("origen");
    const selectDestino = document.getElementById("destino");

    for (let dep in nodos) {
        new google.maps.Marker({
            position: nodos[dep],
            map: map,
            title: dep,
            label: { text: dep[0], color: "white", fontWeight: "bold" }
        });
        selectOrigen.add(new Option(dep, dep));
        selectDestino.add(new Option(dep, dep));
    }
}

function calcularHaversine(c1, c2) {
    const R = 6371; 
    const dLat = (c2.lat - c1.lat) * Math.PI / 180;
    const dLng = (c2.lng - c1.lng) * Math.PI / 180;
    const a = Math.sin(dLat/2)**2 + Math.cos(c1.lat*Math.PI/180) * Math.cos(c2.lat*Math.PI/180) * Math.sin(dLng/2)**2;
    return R * 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
}

function dijkstra(start, end) {
    let distancias = {};
    let anteriores = {};
    let noVisitados = Object.keys(nodos);

    noVisitados.forEach(nodo => {
        distancias[nodo] = Infinity;
        anteriores[nodo] = null;
    });
    distancias[start] = 0;

    while (noVisitados.length > 0) {
        noVisitados.sort((a, b) => distancias[a] - distancias[b]);
        let u = noVisitados.shift();
        if (u === end) break;

        conexiones.forEach(edge => {
            let v = null;
            if (edge[0] === u) v = edge[1];
            else if (edge[1] === u) v = edge[0];

            if (v && noVisitados.includes(v)) {
                let peso = calcularHaversine(nodos[u], nodos[v]);
                let alt = distancias[u] + peso;
                if (alt < distancias[v]) {
                    distancias[v] = alt;
                    anteriores[v] = u;
                }
            }
        });
    }

    let camino = [];
    let actual = end;
    while (actual) {
        camino.push(actual);
        actual = anteriores[actual];
    }
    return { ruta: camino.reverse(), distancia: distancias[end] };
}

function calcularRuta() {
    const origen = document.getElementById("origen").value;
    const destino = document.getElementById("destino").value;

    if (origen === destino) return;

    const resultado = dijkstra(origen, destino);
    
    if (polyline) polyline.setMap(null);
    polyline = new google.maps.Polyline({
        path: resultado.ruta.map(dep => nodos[dep]),
        icons: [{
            icon: { path: google.maps.SymbolPath.FORWARD_CLOSED_ARROW, scale: 3, strokeColor: '#FF0000' },
            offset: '100%',
            repeat: '100px'
        }],
        strokeColor: "#FF0000",
        strokeWeight: 4,
        map: map
    });

    let htmlDesglose = `<h3 style="color:#0044ff;">Ruta desde ${origen}</h3>`;
    resultado.ruta.forEach((dep, index) => {
        htmlDesglose += `<p style="border-bottom: 1px solid #eee; padding: 5px;">
            <strong>${index + 1}.</strong> ${dep}
        </p>`;
    });

    document.getElementById("ruta-desglose").innerHTML = htmlDesglose;
    document.getElementById("info-distancia").innerHTML = `
        <div style="background:#e7f0ff; padding:10px; border-radius:5px; text-align:center;">
            <strong>Distancia total = ${resultado.distancia.toFixed(0)} KM</strong>
        </div>
    `;
}