{
  description = "C++ environment";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-utils.url = github:numtide/flake-utils;
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        # Override the Nix package set to allow unfree packages
        pkgs = import nixpkgs {
          system = system; 
          config.allowUnfree = true; 
        };
      in
      {
        # development environment
        devShells.default = pkgs.mkShell {
          packages = [
            # C/C++ development
            pkgs.gcc
            pkgs.gnumake
            pkgs.gdb
            pkgs.valgrind
          ];

          shellHook = ''
            echo "Welcome to your C++ development environment with Gurobi"
          '';
        };
      }
    );
}