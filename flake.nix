{
  description = "C++ template";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, ... }@inputs: inputs.utils.lib.eachSystem [
    "x86_64-linux" 
  ] (system: let
    pkgs = import nixpkgs {
      inherit system;
    };
  in {
    devShells.default = pkgs.mkShell.override {
      stdenv = pkgs.llvmPackages_18.stdenv;
      # stdenv = pkgs.gcc14Stdenv;
    } rec {
      name = "magic.cpp";

      packages = with pkgs; [
        unzip
	clang-tools_18
      ];

      buildInputs = with pkgs; [
        xmake
      ];
      # see https://github.com/xmake-io/xmake/issues/5138 and https://github.com/NixOS/nixpkgs/issues/314313
      shellHook = ''
        export LD=$CXX
      '';
    };
  });
}
