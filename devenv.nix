{
  pkgs,
  lib,
  config,
  inputs,
  ...
}:

{
  languages.c.enable = true;
  languages.cplusplus.enable = true;

  # https://devenv.sh/git-hooks/
  # git-hooks.hooks.shellcheck.enable = true;

  # See full reference at https://devenv.sh/reference/options/
}
