<<<<<<< HEAD
function submitFormData() {
  let form = document.getElementById("npsiForm");
  form.submit();
}


// Call C from JavaScript
var result = Module.ccall('party3', // name of C function
  'bigint', // return type
  ['bigint'], // argument types
  [myIdx], [setSize], [nTrials]); // arguments

=======
function submitFormData() {
  let form = document.getElementById("npsiForm");
  form.submit();
}


// Call C from JavaScript
var result = Module.ccall('party3', // name of C function
  'bigint', // return type
  ['bigint'], // argument types
  [myIdx], [setSize], [nTrials]); // arguments

>>>>>>> 3c6e9e06 (Merge pull request #9 from eshf/norieworks)
  Module.print()