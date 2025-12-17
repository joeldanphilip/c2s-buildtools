# VEGA Tools
[![pipeline status](https://gitlab.com/cdac-vega/vega-tools-rv32/badges/master/pipeline.svg)](https://gitlab.com/cdac-vega/vega-tools-rv32/-/commits/master)

The VEGA Tools contains the pre compiled toolchains and supporting utilities to compile the riscv programs.

## Quick Start

> For Ubuntu 18.04 (or newer) install below listed packages.

- autoconf
- git

### Installation and setup

Clone the repository and setup the environment varibale by executing script.

```bash
git clone https://gitlab.com/cdac-vega/vega-tools-rv32.git
cd vega-tools-rv32
./setup-env.sh
```
### Compilation

The toolchain path is added to your system PATH variable. Now you can access the toolchain from any new terminal.

> NB: VEGA tools is required to build any programs in **VEGA sdk**.
