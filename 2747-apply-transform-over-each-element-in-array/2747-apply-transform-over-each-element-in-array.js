/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    for(let i=0;i<arr.length;i++){
        let a=fn(arr[i],i);
        arr[i]=a;
    }
    return arr;
};