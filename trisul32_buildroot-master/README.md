## Build the trisul32 linux image using buildroot
```
./build.sh
```

Exit & save the buildroot menuconfig & Linux menuconfig when pop up and continue the build process.

Upon successfull build you find the bbl , bbl.bin files in the same folder.

This file you can transfer to board using the eth_transfer option in vega-tools
