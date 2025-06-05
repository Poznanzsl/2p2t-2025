const rozmiar = 10;
const liczbaMin = 15;
let pola = [];
let graSkonczona = false;
let pierwszyKlik = true;
let liczbaFlag = liczbaMin;

const licznikMin = document.getElementById("licznikMin");

function rozpocznijGre() {
  const plansza = document.getElementById("plansza");
  plansza.innerHTML = "";
  graSkonczona = false;
  pierwszyKlik = true;
  liczbaFlag = liczbaMin;

  document.getElementById("menuPrzegrana").classList.add("menu-ukryte");
  licznikMin.textContent = `Miny: ${liczbaFlag}`;
  pola = [];

  for (let i = 0; i < rozmiar * rozmiar; i++) {
    const pole = document.createElement("div");
    pole.classList.add("pole");
    pole.dataset.index = i;

    pole.addEventListener("click", kliknijPole);
    pole.addEventListener("contextmenu", postawFlage);

    plansza.appendChild(pole);

    pola.push({
      element: pole,
      mina: false,
      odkryte: false,
      liczbaObok: 0,
      flaga: false
    });
  }
}

function kliknijPole(e) {
  if (graSkonczona) return;

  const index = parseInt(e.target.dataset.index);
  const pole = pola[index];

  if (pole.odkryte || pole.flaga) return;

  if (pierwszyKlik) {
    rozmiescMiny(index);
    pierwszyKlik = false;
  }

  odkryjPole(index);
  sprawdzWygrana();
}

function odkryjPole(index) {
  const pole = pola[index];
  if (pole.odkryte || pole.flaga) return;

  pole.odkryte = true;
  pole.element.classList.add("odkryte");
  pole.element.textContent = "";

  if (pole.mina) {
    pole.element.textContent = "💣";
    pole.element.classList.add("mina");
    przegrana();
  } else if (pole.liczbaObok > 0) {
    pole.element.textContent = pole.liczbaObok;
    pole.element.dataset.liczba = pole.liczbaObok;
  } else {
    pobierzSasiedzi(index).forEach(s => {
      const i = parseInt(s.element.dataset.index);
      odkryjPole(i);
    });
  }
}

function postawFlage(e) {
  e.preventDefault();
  if (graSkonczona) return;

  const index = parseInt(e.target.dataset.index);
  const pole = pola[index];

  if (pole.odkryte) return;
  if (!pole.flaga && liczbaFlag === 0) return;

  pole.flaga = !pole.flaga;

  if (pole.flaga) {
    pole.element.textContent = "🚩";
    liczbaFlag--;
  } else {
    pole.element.textContent = "";
    liczbaFlag++;
  }

  licznikMin.textContent = `Miny: ${liczbaFlag}`;
}

function rozmiescMiny(indexZakazany) {
  const zakazane = new Set([indexZakazany]);
  pobierzSasiedzi(indexZakazany).forEach(p => {
    zakazane.add(parseInt(p.element.dataset.index));
  });

  let miny = 0;
  while (miny < liczbaMin) {
    let indeks = Math.floor(Math.random() * pola.length);
    if (!pola[indeks].mina && !zakazane.has(indeks)) {
      pola[indeks].mina = true;
      miny++;
    }
  }

  for (let i = 0; i < pola.length; i++) {
    const sasiedzi = pobierzSasiedzi(i);
    pola[i].liczbaObok = sasiedzi.filter(p => p.mina).length;
  }
}

function pobierzSasiedzi(index) {
  const x = index % rozmiar;
  const y = Math.floor(index / rozmiar);
  const sasiedzi = [];

  for (let dx = -1; dx <= 1; dx++) {
    for (let dy = -1; dy <= 1; dy++) {
      if (dx === 0 && dy === 0) continue;
      const nx = x + dx;
      const ny = y + dy;
      if (nx >= 0 && ny >= 0 && nx < rozmiar && ny < rozmiar) {
        sasiedzi.push(pola[ny * rozmiar + nx]);
      }
    }
  }

  return sasiedzi;
}

function przegrana() {
  graSkonczona = true;

  pola.forEach(p => {
    if (p.mina && !p.odkryte) {
      p.element.textContent = "💣";
      p.element.classList.add("mina");
    }
  });

  document.getElementById("menuPrzegrana").classList.remove("menu-ukryte");
}

function sprawdzWygrana() {
  const odkryteBezMin = pola.filter(p => p.odkryte && !p.mina).length;
  if (odkryteBezMin === rozmiar * rozmiar - liczbaMin) {
    graSkonczona = true;
    alert("🎉 Wygrałeś!");
  }
}

function nowaGra() {
  rozpocznijGre();
}

window.onload = rozpocznijGre;
