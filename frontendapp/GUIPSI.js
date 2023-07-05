const title = document.querySelector("h1");
const titleLength = title.textContent.length;
title.style.setProperty("--typing-steps", titleLength);


const importObject = {
    env: {
      consoleLog: console.log,
    }
  };

WebAssembly.instantiateStreaming(
    fetch('main.wasm'),
    importObject
  ).then(result => {
    const tparty = result.instance.exports.tparty;
    OtBinMain.tparty(pIdx, nParties, tParties, setSize, trials);
  });


