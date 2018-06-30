# README - Fast Light Tool Kit (FLTK) Version 1.4.0

## VERY IMPORTANT TECHNICAL NOTICE

**This FLTK repository is work in progress. Use for testing purposes only.**

  This repository will be replaced by another one in the near future.

  Technically this means:

  * all `Git hashes (SHA1's)` used in this repository will be invalid
    once this repository got replaced
  * we don't accept pull requests for this repository


### Technical background

  Our main source code repository is currently (as of Jun 19, 2018) our
  subversion repository at http://www.fltk.org/software.php#SVN .

  We are in the transition to convert the subversion repository to Git.
  Until this is done we have established Git mirrors of our Subversion
  repository at these two sites:

  * https://github.com/fltk/test-only
  * https://gitlab.com/fltk/fltk

  You may use these Git repositories for testing purposes, but please
  don't rely on their structure (branches) and particularly not on the
  commit (and file/blob) hashes (SHA1's).

  Committing to these Git repositories is not possible since they are
  mirrors of the original Subversion repository.
  
### This Test Repository (fltk-test)

  This repository is **NOT** a mirror of our official Subversion repository.
  It is a first try to convert the Subversion repository to a functional
  Git repository.
 
  FLTK developers are encouraged to use this for testing, committing
  files, using the GitHub web interface, adding and deleting new feature
  branches for testing, using merge requests (even rebasing "private"
  feature branches) and whatever is needed to test Git usage for FLTK.
 
  This repository will **NOT** be used for further development, no
  changes in this repository will be back-ported **automatically**
  to our official Subversion or later Git repositories. Developers
  are responsible for committing *_real_* changes to the Subversion
  repository as well.


## WHAT IS FLTK?

    The Fast Light Tool Kit ("FLTK", pronounced "fulltick") is a
    a cross-platform C++ GUI toolkit for UNIX(r)/Linux(r) (X11),
    Microsoft(r) Windows(r), and MacOS(r) X. FLTK provides
    modern GUI functionality without the bloat and supports 3D
    graphics via OpenGL(r) and its built-in GLUT emulation. It
    was originally developed by Mr. Bill Spitzak and is
    currently maintained by a small group of developers across
    the world with a central repository in the US.

    For more information see file README.
