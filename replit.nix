{ pkgs }: {
	deps = [
		pkgs.vimHugeX
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}