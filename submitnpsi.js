var jsnpsi_val = Module.cwrap("_party3", 'bigint', ['bigint']);

function submitnpsi(){
    console.log("The result of party3 is:", jsnpsi_val([myIdx], [setSize], [nTrials]));
}
