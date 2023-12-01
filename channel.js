import Module from "./channel.js"
const mymod = Module.ccall("_Channel_test", "bigint", ["bigint"]); 
const results = mymod._Channel_test();
console.log(results(0));