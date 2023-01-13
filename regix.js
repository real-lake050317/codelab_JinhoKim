//Write a regix that scans the string for the first occurrence of the word "the" and replaces it with "a". The word "the" should be replaced only if it is a word by itself, so it should not replace "there" or "theatre".

let rThe = /the\b/gi;

let str = "The theatre is the best place to watch the movie";

let newStr = str.replace(rThe, "a");

console.log(newStr);

// what does the regix /the\b/gi do?

// \b is a word boundary, so it will match the word "the" only if it is a word by itself. The "g" flag is for global, so it will replace all occurrences of the word "the" and the "i" flag is for case insensitive, so it will match both "the" and "The".

// write a regix that scans if the password contains at least 8 characters, at least one number, at least one uppercase and one lowercase letter, and one symbol. Use regix groups.

let rPassword = /(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]).{8,}/;

let password = "!dfj3@fjakld9v21aA!";

let isPasswordValid = rPassword.test(password);

console.log(isPasswordValid);