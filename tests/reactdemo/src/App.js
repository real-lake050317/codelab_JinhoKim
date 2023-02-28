import React, { useState } from "react";
import "./App.css";

function App() {
  const [a, setA] = useState(0);

  return (
    <div className="App">
      <button
        className="seongju-button"
        onClick={() => {
          setA(a + 1);
        }}
      >
        김성주
      </button>
      <h1>{a}</h1>
    </div>
  );
}

export default App;
