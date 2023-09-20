Module.onRuntimeInitialized = function () 
{ 

   const hyphen = arguments[0];
   const numparties = arguments[1];
   const partyno = arguments[2];
   const partysetsze= arguments[3];
   const npsioptimisedr= arguments[4];
   const npsiaugparty= arguments[5];
   const npsitparty= arguments[6];
   
   for (var i=0; i<arguments.length(); i++)
   {
         if(hyphen.startsWith("-"))
         {
            if(numparties=="n")
            {
               if(partyno=="p")
               {
                  if(partysetsze=="m")
                  {
                     if(npsioptimisedr=="r")
                     {
                        if(npsiaugparty=="a")
                        {
                           if(npsitparty=="t")
                           {
                                 const npsivalue = Module._usage(arguments[i]); 
                                 console.log(`Choice ${arguments[i]} is ${npsivalue}`);
                           }
                        }
                     }
                  }
               }
            }
         }
      }
};