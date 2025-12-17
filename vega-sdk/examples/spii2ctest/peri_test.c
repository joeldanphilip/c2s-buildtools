#include <stdio.h>
#include <stdint.h>

// ==========================================
// CONFIGURATION: NEW ADDRESS MAP
// ==========================================
// These match the safe, 4KB-aligned addresses we discussed.
#define SPI_BASE      0x10002000UL  // Moved from 0x50010000
#define I2C_BASE      0x10003000UL  // Moved from 0x50000000

// Register Offsets
#define SPI_SR        0x64          // SPI Status Register
#define I2C_SR        0x104         // I2C Status Register

// Helper Macro for 32-bit Access
#define READ_REG(addr)  (*(volatile uint32_t *)(addr))

void test_spi() {
    printf("\n[SPI TEST] Targeting 0x%08lx...\n", SPI_BASE);
    printf("  -> Reading Status Register (Offset 0x64)...\n");

    // If Vivado Address Editor was updated correctly, this will read 0x05 or 0x01
    uint32_t val = READ_REG(SPI_BASE + SPI_SR);
    
    printf("  -> Value: 0x%08lx\n", val);

    if (val == 0xFFFFFFFF) {
        printf("  -> [FAIL] Bus Floating (Did you program the new bitstream?)\n");
    } else {
        printf("  -> [PASS] SPI IP is active at the new address.\n");
    }
}

void test_i2c() {
    printf("\n[I2C TEST] Targeting 0x%08lx...\n", I2C_BASE);
    printf("  -> Reading Status Register (Offset 0x104)...\n");

    // Expected value for I2C is usually 0xC0 (RX/TX Empty)
    uint32_t val = READ_REG(I2C_BASE + I2C_SR);
    
    printf("  -> Value: 0x%08lx\n", val);

    if (val == 0xFFFFFFFF) {
        printf("  -> [FAIL] Bus Floating (Did you program the new bitstream?)\n");
    } else {
        printf("  -> [PASS] I2C IP is active at the new address.\n");
    }
}

int main() {
    printf("\n==========================================\n");
    printf("   PERIPHERAL MIGRATION TEST\n");
    printf("==========================================\n");

    test_spi();
    test_i2c();

    printf("\nTest Complete.\n");
    while(1);
    return 0;
}
