const h = setInterval(idle, 0);
let counter = 0;
function idle() {
  counter++;
  if (counter % 1000000 == 0) process.stdout.write(counter + "\n");
  if (counter >= 10e6) clearInterval(h);
}
