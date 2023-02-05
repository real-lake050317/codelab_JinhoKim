const express = require('express');

const app = express();

app.get("/", (req, res) => {
  res.send("Docker working");
});

app.listen(8080, () => {
  console.log("Server running");
});
