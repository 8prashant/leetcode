/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    var dit = {};
    return function(...args) {
        if( args in dit ) {
            return dit[args];
        } else {
            dit[args] = fn(...args);
            return dit[args];
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */