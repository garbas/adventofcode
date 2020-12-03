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
    g++ day1.cpp -o day1
    g++ day2.cpp -o day2
    #g++ day3.cpp -o day3
  '';
  installPhase = ''
    mkdir $out
    ./day1 > $out/day1
    ./day2 > $out/day2
    #./day3 > $out/day3
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
