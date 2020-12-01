{ pkgs ? import <nixpkgs> {}
}:
pkgs.mkShell {
  name = "adventofcode-c++-2020";
}
