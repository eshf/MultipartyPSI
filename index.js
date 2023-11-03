function submitFormData() 
{
  let form = document.getElementById("npsibutton");
  form.submit();

  Module['onRuntimeInitialized'] = function() {
    console.log("wasm loaded ");
    console.log(Module.ccall); // make sure it's not undefined
    console.log(Module._party3()); 
    // Call C++ from JavaScript
    console.log(Module.ccall("_party3","bigint",["bigint"],[myIdx], [setSize], [nTrials])); // arguments
  }
}

function viewnpsi()
{
    var results = document.getElementById("npsiresults");

    let results = Module.ccall("_party3", "bigint", ["bigint"],[myIdx], [setSize], [nTrials]);

    console.log("The result of party3 is:", results([myIdx], [setSize], [nTrials]));
    
}

