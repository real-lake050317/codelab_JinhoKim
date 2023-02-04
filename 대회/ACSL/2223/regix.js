// regix verification function

function verify(input, answer) {
  var re = new RegExp(input);
  return re.test(answer);
}

input = "00*1*1U11*0*0";
answer = "0000001111111";

console.log(verify(input, answer));