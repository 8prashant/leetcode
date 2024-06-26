// /**
//  * @return {Function}
//  */
// var createHelloWorld = function() {
    
//     return function(...args) {
//         let ans="Hello World";
//         return ans;
//     }
// };

// /**
//  * const f = createHelloWorld();
//  * f(); // "Hello World"
//  */
//  function createHelloWorld(){
//     return function (){
//         return "Hello World";
//     };
// }



// const f =createHelloWorld();
// f();

function createHelloWorld(){
    function f(){
        return "Hello World";
    }
    return f;
}
const m=createHelloWorld();
m();