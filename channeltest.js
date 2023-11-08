import Module from "./channeltest.js"
const mymod = Module.ccall("_Channel_party_test", "bigint", ["bigint"]); 
const Channel_party_test = mymod._Channel_party_test(myIdx);
console.log(_Channel_party_test([0]));