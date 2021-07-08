const pre = [
  ".Lfunc_end",
  ".size ",
  "#",
  ".globl ",
  ".type ",
  ".p2align ",
  ".file ",
  ".intel_syntax ",
  ".text",
];
console.log(
  require("fs")
    .readFileSync(process.argv[2])
    .toString()
    .split("\n")
    .map((l) =>
      l
        .trim()
        .split(/\t| /)
        .map((l) => l.trim())
        .filter(Boolean)
        .join(" ")
    )
    .filter((l) => !pre.some((s) => l.startsWith(s)))
    .map((l) => (l.includes(":") && !l.startsWith(".") ? l : "    " + l))
    .join("\n")
    .trim()
);
