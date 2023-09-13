      Module.onRuntimeInitialized = function () { 
         const num = 2; 
         const result = Module._factorial(num); 
         console.log(`Factorial of ${num} is ${result}`);
      };