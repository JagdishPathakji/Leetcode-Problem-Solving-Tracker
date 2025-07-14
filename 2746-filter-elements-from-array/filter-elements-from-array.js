/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var ans = arr.filter((val,index)=> {
        return fn(val,index);
    })

    return ans;
};