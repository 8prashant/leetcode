/**
 * @param {number} n
 * @return {Function} counter
 */
 
var createCounter = function(n) {
    
    let sum=0;
    return function() {
        console.log(n,sum);
        let nn=n+sum;
        sum=sum+1;
        return nn;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */