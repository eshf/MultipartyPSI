function submitFormData() {
  let form = document.getElementById("npsiForm");
  form.submit();
}

function getnpsiForm()
{
  Module['onRuntimeInitialized'] = function() {
    console.log("wasm loaded ");
    console.log(Module.ccall); // make sure it's not undefined
    console.log(Module._party3()); 
    // Call C from JavaScript
    console.log(Module.ccall('party3', // name of C++ function
    'bigint', // return type
    ['bigint'], // argument types
    [myIdx], [setSize], [nTrials])); // arguments
  }
}