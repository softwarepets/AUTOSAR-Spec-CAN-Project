/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright 2008-2013 Code Red Technologies Ltd,
 * Copyright 2013-2025 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 * Generated linker script file for MIMXRT1176xxxxx
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.30
 * MCUXpresso IDE v24.12 [Build 148] [2025-01-10] on Jun 3, 2025, 5:51:32 PM
 */

MEMORY
{
  /* Define each memory region */
  BOARD_FLASH (rx) : ORIGIN = 0x30000000, LENGTH = 0x4000000 /* 64M bytes (alias Flash) */  
  BOARD_SDRAM (rwx) : ORIGIN = 0x80000000, LENGTH = 0x3000000 /* 48M bytes (alias RAM) */  
  NCACHE_REGION (rwx) : ORIGIN = 0x83000000, LENGTH = 0x1000000 /* 16M bytes (alias RAM2) */  
  SRAM_DTC_cm7 (rwx) : ORIGIN = 0x20000000, LENGTH = 0x40000 /* 256K bytes (alias RAM3) */  
  SRAM_ITC_cm7 (rwx) : ORIGIN = 0x0, LENGTH = 0x40000 /* 256K bytes (alias RAM4) */  
  SRAM_OC1 (rwx) : ORIGIN = 0x20240000, LENGTH = 0x80000 /* 512K bytes (alias RAM5) */  
  SRAM_OC2 (rwx) : ORIGIN = 0x202c0000, LENGTH = 0x80000 /* 512K bytes (alias RAM6) */  
  SRAM_OC_ECC1 (rwx) : ORIGIN = 0x20340000, LENGTH = 0x10000 /* 64K bytes (alias RAM7) */  
  SRAM_OC_ECC2 (rwx) : ORIGIN = 0x20350000, LENGTH = 0x10000 /* 64K bytes (alias RAM8) */  
}

  /* Define a symbol for the top of each memory region */
  __base_BOARD_FLASH = 0x30000000  ; /* BOARD_FLASH */  
  __base_Flash = 0x30000000 ; /* Flash */  
  __top_BOARD_FLASH = 0x30000000 + 0x4000000 ; /* 64M bytes */  
  __top_Flash = 0x30000000 + 0x4000000 ; /* 64M bytes */  
  __base_BOARD_SDRAM = 0x80000000  ; /* BOARD_SDRAM */  
  __base_RAM = 0x80000000 ; /* RAM */  
  __top_BOARD_SDRAM = 0x80000000 + 0x3000000 ; /* 48M bytes */  
  __top_RAM = 0x80000000 + 0x3000000 ; /* 48M bytes */  
  __base_NCACHE_REGION = 0x83000000  ; /* NCACHE_REGION */  
  __base_RAM2 = 0x83000000 ; /* RAM2 */  
  __top_NCACHE_REGION = 0x83000000 + 0x1000000 ; /* 16M bytes */  
  __top_RAM2 = 0x83000000 + 0x1000000 ; /* 16M bytes */  
  __base_SRAM_DTC_cm7 = 0x20000000  ; /* SRAM_DTC_cm7 */  
  __base_RAM3 = 0x20000000 ; /* RAM3 */  
  __top_SRAM_DTC_cm7 = 0x20000000 + 0x40000 ; /* 256K bytes */  
  __top_RAM3 = 0x20000000 + 0x40000 ; /* 256K bytes */  
  __base_SRAM_ITC_cm7 = 0x0  ; /* SRAM_ITC_cm7 */  
  __base_RAM4 = 0x0 ; /* RAM4 */  
  __top_SRAM_ITC_cm7 = 0x0 + 0x40000 ; /* 256K bytes */  
  __top_RAM4 = 0x0 + 0x40000 ; /* 256K bytes */  
  __base_SRAM_OC1 = 0x20240000  ; /* SRAM_OC1 */  
  __base_RAM5 = 0x20240000 ; /* RAM5 */  
  __top_SRAM_OC1 = 0x20240000 + 0x80000 ; /* 512K bytes */  
  __top_RAM5 = 0x20240000 + 0x80000 ; /* 512K bytes */  
  __base_SRAM_OC2 = 0x202c0000  ; /* SRAM_OC2 */  
  __base_RAM6 = 0x202c0000 ; /* RAM6 */  
  __top_SRAM_OC2 = 0x202c0000 + 0x80000 ; /* 512K bytes */  
  __top_RAM6 = 0x202c0000 + 0x80000 ; /* 512K bytes */  
  __base_SRAM_OC_ECC1 = 0x20340000  ; /* SRAM_OC_ECC1 */  
  __base_RAM7 = 0x20340000 ; /* RAM7 */  
  __top_SRAM_OC_ECC1 = 0x20340000 + 0x10000 ; /* 64K bytes */  
  __top_RAM7 = 0x20340000 + 0x10000 ; /* 64K bytes */  
  __base_SRAM_OC_ECC2 = 0x20350000  ; /* SRAM_OC_ECC2 */  
  __base_RAM8 = 0x20350000 ; /* RAM8 */  
  __top_SRAM_OC_ECC2 = 0x20350000 + 0x10000 ; /* 64K bytes */  
  __top_RAM8 = 0x20350000 + 0x10000 ; /* 64K bytes */  
