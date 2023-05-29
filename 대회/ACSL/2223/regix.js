// regix verification function

function verify(answer) {
  var re = new RegExp("[^e][a-hlr-y]*[\s]*[a-n]*[^mr]*[\S]*[0-9]*");
  return re.test(answer);
}

answer = "python 8";

console.log(verify(answer));