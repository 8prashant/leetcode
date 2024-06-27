/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let sum=0;
    return {
      increment:function(){
        sum+=1;
        return init+sum;
      },
      reset:function(){
        sum=0;
        return init+sum;
      },
      decrement:function(){
        sum-=1;
        return init+sum;
      } 
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */