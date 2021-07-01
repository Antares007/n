require("net")
  .createServer((s) => {
    s.on("data", (d) => {
      s.write(d);
    });
  })
  .listen(8000);
