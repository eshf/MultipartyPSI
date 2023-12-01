    const importObject = {
      env: {
        memory: new WebAssembly.Memory({ initial: 256 }),
      }
    };

    WebAssembly.instantiateStreaming(fetch("viewpsi.wasm"),importObject).then(result => {
      const npsi = result.instance.exports.npsi;
    });