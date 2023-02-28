import express from "express";
import morgan from 'morgan';

const app = express();

app.use(morgan('dev'));

app.get("/", (req, res) => {
  res.send("김성주 잘생겼다");
});

app.listen(8800, () => {
  console.log("Server started on port 3000");
});
