function ratelimit(fnn, delay) {
  let run = true;

  return function (...args) {
    if (!run) {
      return; 
    }

    fnn.apply(this, args);
    run = false;

    setTimeout(() => {
      run = true; 
    }, delay);
  };
}


// Example
function hello() {
  console.log("Hello!");
}

const limitedFunction = ratelimit(hello, 2000);

limitedFunction(); 
