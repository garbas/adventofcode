{ pkgs ? import <nixpkgs> {}
, 
}:
pkgs.stdenv.mkDerivation {
  name = "adventofcode-c++-2020";
  src = ./.;
  buildInputs = with pkgs; [
    # development tools
    fd
    entr
  ];
  buildPhase = ''
    g++ day1.cpp -o day1.out
    g++ day2.cpp -o day2.out
    g++ day3.cpp -o day3.out
    g++ day4.cpp -o day4.out
    g++ day5.cpp -o day5.out
  '';
  installPhase = ''
    mkdir $out
    ./day1.out > $out/day1
    ./day2.out > $out/day2
    ./day3.out > $out/day3
    ./day4.out > $out/day4
    ./day5.out > $out/day5
  '';
  doInstallCheck = true;
  installCheckInputs = with pkgs; [
    bats
  ];
  installCheckPhase = ''
    bats ./verify-results.sh
  '';
  shellHook = ''
    echo "URL: https://adventofcode.com/2020"
    echo
    echo "Happy hacking!"
  '';

}
