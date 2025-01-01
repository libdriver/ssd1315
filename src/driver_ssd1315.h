/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_ssd1315.h
 * @brief     driver ssd1315 header file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2024-11-30
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2024/11/30  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_SSD1315_H
#define DRIVER_SSD1315_H

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup ssd1315_driver ssd1315 driver function
 * @brief    ssd1315 driver modules
 * @{
 */

/**
 * @addtogroup ssd1315_base_driver
 * @{
 */

/**
 * @brief ssd1315 interface enumeration definition
 */
typedef enum
{
    SSD1315_INTERFACE_IIC = 0x00,        /**< interface iic */
    SSD1315_INTERFACE_SPI = 0x01,        /**< interface spi */
} ssd1315_interface_t;

/**
 * @brief ssd1315 address pin enumeration definition
 */
typedef enum  
{
    SSD1315_ADDR_SA0_0 = 0x78,        /**< address pin GND */
    SSD1315_ADDR_SA0_1 = 0x7A,        /**< address pin VCC */
} ssd1315_address_t;

/**
 * @brief ssd1315 memory addressing mode enumeration definition
 */
typedef enum  
{
    SSD1315_MEMORY_ADDRESSING_MODE_HORIZONTAL = 0x00,        /**< horizontal addressing mode */
    SSD1315_MEMORY_ADDRESSING_MODE_VERTICAL   = 0x01,        /**< vertical addressing mode */
    SSD1315_MEMORY_ADDRESSING_MODE_PAGE       = 0x02,        /**< page addressing mode */
} ssd1315_memory_addressing_mode_t;

/**
 * @brief ssd1315 fade blinking mode enumeration definition
 */
typedef enum  
{
    SSD1315_FADE_BLINKING_MODE_DISABLE  = 0x00,        /**< disable fade blinking mode */
    SSD1315_FADE_BLINKING_MODE_FADE_OUT = 0x02,        /**< fade out fade blinking mode */
    SSD1315_FADE_BLINKING_MODE_BLINKING = 0x03,        /**< blinking fade blinking mode */
} ssd1315_fade_blinking_mode_t;

/**
 * @brief ssd1315 horizontal scroll enumeration definition
 */
typedef enum  
{
    SSD1315_HORIZONTAL_SCROLL_DISABLE = 0x00,        /**< disable horizontal scroll */
    SSD1315_HORIZONTAL_SCROLL_ENABLE  = 0x01,        /**< enable horizontal scroll */
} ssd1315_horizontal_scroll_t;

/**
 * @brief ssd1315 scroll frame enumeration definition
 */
typedef enum  
{
    SSD1315_SCROLL_FRAME_2    = 0x07,        /**< scroll frame 2 */
    SSD1315_SCROLL_FRAME_3    = 0x04,        /**< scroll frame 3 */
    SSD1315_SCROLL_FRAME_4    = 0x05,        /**< scroll frame 4 */
    SSD1315_SCROLL_FRAME_5    = 0x06,        /**< scroll frame 5 */
    SSD1315_SCROLL_FRAME_6    = 0x00,        /**< scroll frame 6 */
    SSD1315_SCROLL_FRAME_32   = 0x01,        /**< scroll frame 32 */
    SSD1315_SCROLL_FRAME_64   = 0x02,        /**< scroll frame 64 */
    SSD1315_SCROLL_FRAME_128  = 0x03,        /**< scroll frame 128 */
} ssd1315_scroll_frame_t;

/**
 * @brief ssd1315 charge pump enumeration definition
 */
typedef enum  
{
    SSD1315_CHARGE_PUMP_DISABLE = 0x00,        /**< charge pump disable */
    SSD1315_CHARGE_PUMP_ENABLE  = 0x01,        /**< charge pump enable */
} ssd1315_charge_pump_t;

/**
 * @brief ssd1315 charge pump mode enumeration definition
 */
typedef enum  
{
    SSD1315_CHARGE_PUMP_MODE_7P5V = 0x00,        /**< 7.5V */
    SSD1315_CHARGE_PUMP_MODE_8P5V = 0x02,        /**< 8.5V */
    SSD1315_CHARGE_PUMP_MODE_9P0V = 0x03,        /**< 9.0V */
} ssd1315_charge_pump_mode_t;

/**
 * @brief ssd1315 segment column remap enumeration definition
 */
typedef enum  
{
    SSD1315_SEGMENT_COLUMN_ADDRESS_0   = 0x00,        /**< segment column remap address 0 */
    SSD1315_SEGMENT_COLUMN_ADDRESS_127 = 0x01,        /**< segment column remap address 127 */
} ssd1315_segment_column_remap_t;

/**
 * @brief ssd1315 entire display enumeration definition
 */
typedef enum  
{
    SSD1315_ENTIRE_DISPLAY_OFF = 0x00,        /**< entire display off */
    SSD1315_ENTIRE_DISPLAY_ON  = 0x01,        /**< entire display on */
} ssd1315_entire_display_t;

/**
 * @brief ssd1315 display mode enumeration definition
 */
typedef enum  
{
    SSD1315_DISPLAY_MODE_NORMAL  = 0x00,        /**< display mode normal */
    SSD1315_DISPLAY_MODE_INVERSE = 0x01,        /**< display mode inverse */
} ssd1315_display_mode_t;

/**
 * @brief ssd1315 display enumeration definition
 */
typedef enum  
{
    SSD1315_DISPLAY_OFF = 0x00,        /**< close display */
    SSD1315_DISPLAY_ON  = 0x01,        /**< open display */
} ssd1315_display_t;

/**
 * @brief ssd1315 scan direction enumeration definition
 */
typedef enum  
{
    SSD1315_SCAN_DIRECTION_COM0_START   = 0x00,        /**< scan direction com 0 start */
    SSD1315_SCAN_DIRECTION_COMN_1_START = 0x01,        /**< scan direction com N-1 start */
} ssd1315_scan_direction_t;

/**
 * @brief ssd1315 zoom in enumeration definition
 */
typedef enum  
{
    SSD1315_ZOOM_IN_DISABLE = 0x00,        /**< disable zoom in */
    SSD1315_ZOOM_IN_ENABLE  = 0x01,        /**< enable zoom in */
} ssd1315_zoom_in_t;

/**
 * @brief ssd1315 pin conf enumeration definition
 */
typedef enum  
{
    SSD1315_PIN_CONF_SEQUENTIAL  = 0x00,        /**< pin conf sequential */
    SSD1315_PIN_CONF_ALTERNATIVE = 0x01,        /**< pin conf alternative */
} ssd1315_pin_conf_t;

/**
 * @brief ssd1315 left right remap enumeration definition
 */
typedef enum  
{
    SSD1315_LEFT_RIGHT_REMAP_DISABLE = 0x00,        /**< disable left right remap */
    SSD1315_LEFT_RIGHT_REMAP_ENABLE  = 0x01,        /**< enable left right remap */
} ssd1315_left_right_remap_t;

/**
 * @brief ssd1315 deselect level enumeration definition
 */
typedef enum  
{
    SSD1315_DESELECT_LEVEL_0P65 = 0x00,        /**< deselect level 0.65 */
    SSD1315_DESELECT_LEVEL_0P77 = 0x02,        /**< deselect level 0.77 */
    SSD1315_DESELECT_LEVEL_0P83 = 0x03,        /**< deselect level 0.83 */
} ssd1315_deselect_level_t;

/**
 * @brief ssd1315 iref enumeration definition
 */
typedef enum  
{
    SSD1315_IREF_DISABLE = 0x00,        /**< disable iref */
    SSD1315_IREF_ENABLE  = 0x01,        /**< enable iref */
} ssd1315_iref_t;

/**
 * @brief ssd1315 iref value enumeration definition
 */
typedef enum  
{
    SSD1315_IREF_VALUE_19UA_150UA = 0x00,        /**< internal iref setting: 19uA, output maximum iseg 150uA */
    SSD1315_IREF_VALUE_30UA_240UA = 0x01,        /**< internal iref setting: 30uA, output maximum iseg 240uA */
} ssd1315_iref_value_t;

/**
 * @brief ssd1315 font enumeration definition
 */
typedef enum  
{
    SSD1315_FONT_12 = 0x0C,        /**< font 12 */
    SSD1315_FONT_16 = 0x10,        /**< font 16 */
    SSD1315_FONT_24 = 0x18,        /**< font 24 */
} ssd1315_font_t;

/**
 * @brief ssd1315 handle structure definition
 */
typedef struct ssd1315_handle_s
{
    uint8_t (*iic_init)(void);                                                          /**< point to an iic_init function address */
    uint8_t (*iic_deinit)(void);                                                        /**< point to an iic_deinit function address */
    uint8_t (*iic_write)(uint8_t addr, uint8_t reg, uint8_t *buf, uint16_t len);        /**< point to an iic_write function address */
    uint8_t (*spi_init)(void);                                                          /**< point to a spi_init function address */
    uint8_t (*spi_deinit)(void);                                                        /**< point to a spi_deinit function address */
    uint8_t (*spi_write_cmd)(uint8_t *buf, uint16_t len);                               /**< point to a spi_write_cmd function address */
    uint8_t (*spi_cmd_data_gpio_init)(void);                                            /**< point to a spi_cmd_data_gpio_init function address */
    uint8_t (*spi_cmd_data_gpio_deinit)(void);                                          /**< point to a spi_cmd_data_gpio_deinit function address */
    uint8_t (*spi_cmd_data_gpio_write)(uint8_t value);                                  /**< point to a spi_cmd_data_gpio_write function address */
    uint8_t (*reset_gpio_init)(void);                                                   /**< point to a reset_gpio_init function address */
    uint8_t (*reset_gpio_deinit)(void);                                                 /**< point to a reset_gpio_deinit function address */
    uint8_t (*reset_gpio_write)(uint8_t value);                                         /**< point to a reset_gpio_write function address */
    void (*debug_print)(const char *const fmt, ...);                                    /**< point to a debug_print function address */
    void (*delay_ms)(uint32_t ms);                                                      /**< point to a delay_ms function address */
    uint8_t inited;                                                                     /**< inited flag */
    uint8_t iic_addr;                                                                   /**< iic address */
    uint8_t iic_spi;                                                                    /**< iic spi type */
    uint8_t gram[128][8];                                                               /**< gram buffer */
} ssd1315_handle_t;

/**
 * @brief ssd1315 information structure definition
 */
typedef struct ssd1315_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} ssd1315_info_t;

/**
 * @}
 */

/**
 * @defgroup ssd1315_link_driver ssd1315 link driver function
 * @brief    ssd1315 link driver modules
 * @ingroup  ssd1315_driver
 * @{
 */

/**
 * @brief     initialize ssd1315_handle_t structure
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] STRUCTURE ssd1315_handle_t
 * @note      none
 */
#define DRIVER_SSD1315_LINK_INIT(HANDLE, STRUCTURE)                     memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link iic_init function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to an iic_init function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_IIC_INIT(HANDLE, FUC)                      (HANDLE)->iic_init = FUC

/**
 * @brief     link iic_deinit function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to an iic_deinit function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_IIC_DEINIT(HANDLE, FUC)                    (HANDLE)->iic_deinit = FUC

/**
 * @brief     link iic_write function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to an iic_write function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_IIC_WRITE(HANDLE, FUC)                     (HANDLE)->iic_write = FUC

/**
 * @brief     link spi_init function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a spi_init function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_SPI_INIT(HANDLE, FUC)                      (HANDLE)->spi_init = FUC

/**
 * @brief     link spi_deinit function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a spi_deinit function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_SPI_DEINIT(HANDLE, FUC)                    (HANDLE)->spi_deinit = FUC

/**
 * @brief     link spi_write_cmd function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a spi_write_cmd function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_SPI_WRITE_COMMAND(HANDLE, FUC)             (HANDLE)->spi_write_cmd = FUC

/**
 * @brief     link spi_cmd_data_gpio_init function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a spi_cmd_data_gpio_init function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_SPI_COMMAND_DATA_GPIO_INIT(HANDLE, FUC)    (HANDLE)->spi_cmd_data_gpio_init = FUC

/**
 * @brief     link spi_cmd_data_gpio_deinit function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a spi_cmd_data_gpio_deinit function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_SPI_COMMAND_DATA_GPIO_DEINIT(HANDLE, FUC)  (HANDLE)->spi_cmd_data_gpio_deinit = FUC

/**
 * @brief     link spi_cmd_data_gpio_write function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a spi_cmd_data_gpio_write function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_SPI_COMMAND_DATA_GPIO_WRITE(HANDLE, FUC)   (HANDLE)->spi_cmd_data_gpio_write = FUC

/**
 * @brief     link reset_gpio_init function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a reset_gpio_init function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_RESET_GPIO_INIT(HANDLE, FUC)               (HANDLE)->reset_gpio_init = FUC

/**
 * @brief     link reset_gpio_deinit function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a reset_gpio_deinit function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_RESET_GPIO_DEINIT(HANDLE, FUC)             (HANDLE)->reset_gpio_deinit = FUC

/**
 * @brief     link reset_gpio_write function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a reset_gpio_write function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_RESET_GPIO_WRITE(HANDLE, FUC)              (HANDLE)->reset_gpio_write = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a delay_ms function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_DELAY_MS(HANDLE, FUC)                      (HANDLE)->delay_ms = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE pointer to an ssd1315 handle structure
 * @param[in] FUC pointer to a debug_print function address
 * @note      none
 */
#define DRIVER_SSD1315_LINK_DEBUG_PRINT(HANDLE, FUC)                   (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup ssd1315_base_driver ssd1315 base driver function
 * @brief    ssd1315 base driver modules
 * @ingroup  ssd1315_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info pointer to an ssd1315 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t ssd1315_info(ssd1315_info_t *info);

/**
 * @brief     set the chip interface
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] interface chip interface
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t ssd1315_set_interface(ssd1315_handle_t *handle, ssd1315_interface_t interface);

/**
 * @brief      get the chip interface
 * @param[in]  *handle pointer to an ssd1315 handle structure
 * @param[out] *interface pointer to a chip interface buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t ssd1315_get_interface(ssd1315_handle_t *handle, ssd1315_interface_t *interface);

/**
 * @brief     set the chip iic address
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] addr_pin iic address
 * @return    status code
 *            - 0 success
 *            - 2 handle is NULL
 * @note      none
 */
uint8_t ssd1315_set_addr_pin(ssd1315_handle_t *handle, ssd1315_address_t addr_pin);

/**
 * @brief      get the chip iic address
 * @param[in]  *handle pointer to an ssd1315 handle structure
 * @param[out] *addr_pin pointer to an iic address buffer
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t ssd1315_get_addr_pin(ssd1315_handle_t *handle, ssd1315_address_t *addr_pin);

/**
 * @brief     initialize the chip
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic or spi initialization failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 *            - 4 reset failed
 *            - 5 command && data init failed
 *            - 6 interface param is invalid
 * @note      none
 */
uint8_t ssd1315_init(ssd1315_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 iic or spi deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 power down failed
 *            - 5 reset gpio deinit failed
 *            - 6 command && data deinit failed
 *            - 7 interface param is invalid
 * @note      none
 */
uint8_t ssd1315_deinit(ssd1315_handle_t *handle);

/**
 * @brief     clear the screen
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 clear failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_clear(ssd1315_handle_t *handle);

/**
 * @brief     update the gram data
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 gram update failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_gram_update(ssd1315_handle_t *handle);

/**
 * @brief     write a point
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] x coordinate x
 * @param[in] y coordinate y
 * @param[in] data written data
 * @return    status code
 *            - 0 success
 *            - 1 write point failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 x or y is invalid
 * @note      none
 */
uint8_t ssd1315_write_point(ssd1315_handle_t *handle, uint8_t x, uint8_t y, uint8_t data);

/**
 * @brief      read a point
 * @param[in]  *handle pointer to an ssd1315 handle structure
 * @param[in]  x coordinate x
 * @param[in]  y coordinate y
 * @param[out] *data pointer to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 read point failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 x or y is invalid
 * @note       none
 */
uint8_t ssd1315_read_point(ssd1315_handle_t *handle, uint8_t x, uint8_t y, uint8_t *data);

/**
 * @brief     write a point in the gram
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] x coordinate x
 * @param[in] y coordinate y
 * @param[in] data written data
 * @return    status code
 *            - 0 success
 *            - 1 gram write point failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 x or y is invalid
 * @note      none
 */
uint8_t ssd1315_gram_write_point(ssd1315_handle_t *handle, uint8_t x, uint8_t y, uint8_t data);

/**
 * @brief      read a point from the gram
 * @param[in]  *handle pointer to an ssd1315 handle structure
 * @param[in]  x coordinate x
 * @param[in]  y coordinate y
 * @param[out] *data pointer to a data buffer
 * @return     status code
 *             - 0 success
 *             - 1 gram read point failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 *             - 4 x or y is invalid
 * @note       none
 */
uint8_t ssd1315_gram_read_point(ssd1315_handle_t *handle, uint8_t x, uint8_t y, uint8_t *data);

/**
 * @brief     draw a string in the gram
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] x coordinate x
 * @param[in] y coordinate y
 * @param[in] *str pointer to a write string address
 * @param[in] len length of the string
 * @param[in] color display color
 * @param[in] font display font size
 * @return    status code
 *            - 0 success
 *            - 1 gram write string failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 x or y is invalid
 * @note      none
 */
uint8_t ssd1315_gram_write_string(ssd1315_handle_t *handle, uint8_t x, uint8_t y, char *str, uint16_t len, uint8_t color, ssd1315_font_t font);

/**
 * @brief     fill a rectangle in the gram
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] left left coordinate x
 * @param[in] top top coordinate y
 * @param[in] right right coordinate x
 * @param[in] bottom bottom coordinate y
 * @param[in] color display color
 * @return    status code
 *            - 0 success
 *            - 1 gram fill rect failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 left or top is invalid
 *            - 5 right or bottom is invalid
 *            - 6 left > right or top > bottom
 * @note      none
 */
uint8_t ssd1315_gram_fill_rect(ssd1315_handle_t *handle, uint8_t left, uint8_t top, uint8_t right, uint8_t bottom, uint8_t color);

/**
 * @brief     draw a picture in the gram
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] left left coordinate x
 * @param[in] top top coordinate y
 * @param[in] right right coordinate x
 * @param[in] bottom bottom coordinate y
 * @param[in] *img pointer to an image buffer
 * @return    status code
 *            - 0 success
 *            - 1 gram draw picture failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 left or top is invalid
 *            - 5 right or bottom is invalid
 *            - 6 left > right or top > bottom
 * @note      none
 */
uint8_t ssd1315_gram_draw_picture(ssd1315_handle_t *handle, uint8_t left, uint8_t top, uint8_t right, uint8_t bottom, uint8_t *img);

/**
 * @brief     set the low column start address
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] addr low column start address
 * @return    status code
 *            - 0 success
 *            - 1 set low column start address failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 addr is invalid
 * @note      addr <= 0xF
 */
uint8_t ssd1315_set_low_column_start_address(ssd1315_handle_t *handle, uint8_t addr);

/**
 * @brief     set the high column start address
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] addr high column start address
 * @return    status code
 *            - 0 success
 *            - 1 set high column start address failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 addr is invalid
 * @note      addr <= 0x7
 */
uint8_t ssd1315_set_high_column_start_address(ssd1315_handle_t *handle, uint8_t addr);

/**
 * @brief     set the memory addressing mode
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] mode memory addressing mode
 * @return    status code
 *            - 0 success
 *            - 1 set memory addressing mode failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_memory_addressing_mode(ssd1315_handle_t *handle, ssd1315_memory_addressing_mode_t mode);

/**
 * @brief     set the column address range
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] start_addr column start address
 * @param[in] end_addr column end address
 * @return    status code
 *            - 0 success
 *            - 1 set column address range failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start addr is invalid
 *            - 5 end addr is invalid
 * @note      start addr and end addr can't be over 0x7F
 */
uint8_t ssd1315_set_column_address_range(ssd1315_handle_t *handle, uint8_t start_addr, uint8_t end_addr);

/**
 * @brief     set the page address range
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] start_addr page start address
 * @param[in] end_addr page end address
 * @return    status code
 *            - 0 success
 *            - 1 set page address range failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start addr is invalid
 *            - 5 end addr is invalid
 * @note      start addr and end addr can't be over 0x07
 */
uint8_t ssd1315_set_page_address_range(ssd1315_handle_t *handle, uint8_t start_addr, uint8_t end_addr);

/**
 * @brief     set the fade blinking mode
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] mode fade blinking mode
 * @param[in] frames fade or blinking frames
 * @return    status code
 *            - 0 success
 *            - 1 set fade blinking mode failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 frames is invalid
 * @note      frames max is 0x0F and div is (frames + 1) * 8
 */
uint8_t ssd1315_set_fade_blinking_mode(ssd1315_handle_t *handle, ssd1315_fade_blinking_mode_t mode, uint8_t frames);

/**
 * @brief     set the right horizontal scroll
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] start_page_addr start page address
 * @param[in] end_page_addr end page address
 * @param[in] frames scroll frames
 * @return    status code
 *            - 0 success
 *            - 1 set right horizontal scroll failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start page addr is invalid
 *            - 5 end page addr is invalid
 * @note       start_page_addr <= 0x07, end_page_addr <= 0x07
 */
uint8_t ssd1315_set_right_horizontal_scroll(ssd1315_handle_t *handle, uint8_t start_page_addr, uint8_t end_page_addr, 
                                            ssd1315_scroll_frame_t frames);

/**
 * @brief     set the left horizontal scroll
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] start_page_addr start page address
 * @param[in] end_page_addr end page address
 * @param[in] frames scroll frames
 * @return    status code
 *            - 0 success
 *            - 1 set left horizontal scroll failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start_page_addr is invalid
 *            - 5 end_page_addr is invalid
 * @note      start_page_addr <= 0x07, end_page_addr <= 0x07
 */
uint8_t ssd1315_set_left_horizontal_scroll(ssd1315_handle_t *handle, uint8_t start_page_addr, uint8_t end_page_addr, 
                                           ssd1315_scroll_frame_t frames);

/**
 * @brief     set the vertical right horizontal scroll
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] enable bool value
 * @param[in] start_page_addr start page address
 * @param[in] end_page_addr end page address
 * @param[in] vertical_scrolling_offset vertical scrolling offset
 * @param[in] frames scroll frames
 * @param[in] start_column_addr start column address
 * @param[in] end_column_addr end column address
 * @return    status code
 *            - 0 success
 *            - 1 set vertical right horizontal scroll failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start_page_addr is invalid
 *            - 5 end_page_addr is invalid
 *            - 6 vertical scrolling offset is invalid
 *            - 7 start column addr is invalid
 *            - 8 end column addr is invalid
 * @note      start_page_addr <= 0x07, end_page_addr <= 0x07, vertical_scrolling_offset <= 0x3F
 *            start_column_addr <= 0x7F, end_column_addr <= 0x7F
 */
uint8_t ssd1315_set_vertical_right_horizontal_scroll(ssd1315_handle_t *handle, ssd1315_horizontal_scroll_t enable,
                                                     uint8_t start_page_addr, uint8_t end_page_addr, 
                                                     uint8_t vertical_scrolling_offset, ssd1315_scroll_frame_t frames,
                                                     uint8_t start_column_addr, uint8_t end_column_addr);

/**
 * @brief     set the vertical left horizontal scroll
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] enable bool value
 * @param[in] start_page_addr start page address
 * @param[in] end_page_addr end page address
 * @param[in] vertical_scrolling_offset vertical scrolling offset
 * @param[in] frames scroll frames
 * @param[in] start_column_addr start column address
 * @param[in] end_column_addr end column address
 * @return    status code
 *            - 0 success
 *            - 1 set vertical left horizontal scroll failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start_page_addr is invalid
 *            - 5 end_page_addr is invalid
 *            - 6 vertical scrolling offset is invalid
 *            - 7 start column addr is invalid
 *            - 8 end column addr is invalid
 * @note      start_page_addr <= 0x07, end_page_addr <= 0x07, vertical_scrolling_offset <= 0x3F
 *            start_column_addr <= 0x7F, end_column_addr <= 0x7F
 */
uint8_t ssd1315_set_vertical_left_horizontal_scroll(ssd1315_handle_t *handle, ssd1315_horizontal_scroll_t enable,
                                                    uint8_t start_page_addr, uint8_t end_page_addr, 
                                                    uint8_t vertical_scrolling_offset, ssd1315_scroll_frame_t frames,
                                                    uint8_t start_column_addr, uint8_t end_column_addr);

/**
 * @brief     deactivate the scroll
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 deactivate scroll failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_deactivate_scroll(ssd1315_handle_t *handle);

/**
 * @brief     activate the scroll
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 activate scroll failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_activate_scroll(ssd1315_handle_t *handle);

/**
 * @brief     set the display start line
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] l start line
 * @return    status code
 *            - 0 success
 *            - 1 set display start line failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 line is invalid
 * @note      line <= 0x3F
 */
uint8_t ssd1315_set_display_start_line(ssd1315_handle_t *handle, uint8_t l);

/**
 * @brief     set the display contrast
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] contrast display contrast
 * @return    status code
 *            - 0 success
 *            - 1 set contrast failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_contrast(ssd1315_handle_t *handle, uint8_t contrast);

/**
 * @brief     enable or disable the charge pump
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] enable bool value
 * @param[in] mode charge pump mode
 * @return    status code
 *            - 0 success
 *            - 1 set charge pump failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_charge_pump(ssd1315_handle_t *handle, ssd1315_charge_pump_t enable, ssd1315_charge_pump_mode_t mode);

/**
 * @brief     set the segment remap
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] remap segment remap param
 * @return    status code
 *            - 0 success
 *            - 1 set segment remap failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_segment_remap(ssd1315_handle_t *handle, ssd1315_segment_column_remap_t remap);

/**
 * @brief     set the vertical scroll area
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] start_row start row
 * @param[in] end_row end row
 * @return    status code
 *            - 0 success
 *            - 1 set vertical scroll area failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start_row is invalid
 *            - 5 end_row is invalid
 *            - 6 end_row > start_row
 * @note      start_row <= 0x3F, end_row <= 0x7F, start_row >= end_row
 */
uint8_t ssd1315_set_vertical_scroll_area(ssd1315_handle_t *handle, uint8_t start_row, uint8_t end_row);

/**
 * @brief     enable or disable the entire display
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] enable bool value
 * @return    status code
 *            - 0 success
 *            - 1 set entire display failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_entire_display(ssd1315_handle_t *handle, ssd1315_entire_display_t enable);

/**
 * @brief     set the display mode
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] mode display mode
 * @return    status code
 *            - 0 success
 *            - 1 set display mode failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_display_mode(ssd1315_handle_t *handle, ssd1315_display_mode_t mode);

/**
 * @brief     set the multiplex ratio
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] multiplex multiplex ratio
 * @return    status code
 *            - 0 success
 *            - 1 set multiplex ratio failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 multiplex is too small
 *            - 5 multiplex is too large
 * @note      multiplex must be over 0x0E and less than 0x40
 */
uint8_t ssd1315_set_multiplex_ratio(ssd1315_handle_t *handle, uint8_t multiplex);

/**
 * @brief     enable or disable the display
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] on_off bool value
 * @return    status code
 *            - 0 success
 *            - 1 set display failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_display(ssd1315_handle_t *handle, ssd1315_display_t on_off);

/**
 * @brief     set the page address
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] addr page address
 * @return    status code
 *            - 0 success
 *            - 1 set page address failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 addr is invalid
 * @note      addr <= 0x07
 */
uint8_t ssd1315_set_page_address(ssd1315_handle_t *handle, uint8_t addr);

/**
 * @brief     set the scan direction
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] dir scan direction
 * @return    status code
 *            - 0 success
 *            - 1 set scan direction failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_scan_direction(ssd1315_handle_t *handle, ssd1315_scan_direction_t dir);

/**
 * @brief     set the display offset
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] offset display offset
 * @return    status code
 *            - 0 success
 *            - 1 set display offset failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 offset is invalid
 * @note      offset <= 0x3F
 */
uint8_t ssd1315_set_display_offset(ssd1315_handle_t *handle, uint8_t offset);

/**
 * @brief     set the display clock
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] oscillator_frequency oscillator frequency
 * @param[in] clock_divide clock divide
 * @return    status code
 *            - 0 success
 *            - 1 set display clock failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 oscillator frequency is invalid
 *            - 5 clock divide is invalid
 * @note      oscillator_frequency <= 0x0F, clock_divide <= 0x0F
 */
uint8_t ssd1315_set_display_clock(ssd1315_handle_t *handle, uint8_t oscillator_frequency, uint8_t clock_divide);

/**
 * @brief     set the display zoom in
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] zoom display zoom in
 * @return    status code
 *            - 0 success
 *            - 1 set zoom in failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_zoom_in(ssd1315_handle_t *handle, ssd1315_zoom_in_t zoom);

/**
 * @brief     set the pre charge period
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] phase1_period phase1 period
 * @param[in] phase2_period phase2 period
 * @return    status code
 *            - 0 success
 *            - 1 set pre charge period failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 phase1 period is invalid
 *            - 5 phase2 period is invalid
 * @note      phase1_period <= 0x0F, phase2_period <= 0x0F
 */
uint8_t ssd1315_set_precharge_period(ssd1315_handle_t *handle, uint8_t phase1_period, uint8_t phase2_period);

/**
 * @brief     set the hardware com pins
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] conf pin conf
 * @param[in] remap left right remap
 * @return    status code
 *            - 0 success
 *            - 1 set com pins hardware conf failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_com_pins_hardware_conf(ssd1315_handle_t *handle, ssd1315_pin_conf_t conf, ssd1315_left_right_remap_t remap);

/**
 * @brief     set the deselect level
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] level deselect level
 * @return    status code
 *            - 0 success
 *            - 1 set deselect level failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_deselect_level(ssd1315_handle_t *handle, ssd1315_deselect_level_t level);

/**
 * @brief     set iref
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] enable bool value
 * @param[in] iref set iref
 * @return    status code
 *            - 0 success
 *            - 1 set iref failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_set_iref(ssd1315_handle_t *handle, ssd1315_iref_t enable, ssd1315_iref_value_t iref);

/**
 * @brief     set right horizontal scroll by one column
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] start_page start page
 * @param[in] end_page end page
 * @param[in] start_column_addr start column address
 * @param[in] end_column_addr end column address
 * @return    status code
 *            - 0 success
 *            - 1 set right horizontal scroll by one column failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start_page > 5
 *            - 5 end_page > 5
 *            - 6 start_column_addr > 0x7F
 *            - 7 end_column_addr > 0x7F
 * @note      start_page <= 5, end_page <= 5, start_column_addr <= 0x7F, end_column_addr <= 0x7F
 */
uint8_t ssd1315_set_right_horizontal_scroll_one_column(ssd1315_handle_t *handle, uint8_t start_page, uint8_t end_page,
                                                       uint8_t start_column_addr, uint8_t end_column_addr);

/**
 * @brief     set left horizontal scroll by one column
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] start_page start page
 * @param[in] end_page end page
 * @param[in] start_column_addr start column address
 * @param[in] end_column_addr end column address
 * @return    status code
 *            - 0 success
 *            - 1 set left horizontal scroll by one column failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 start_page > 5
 *            - 5 end_page > 5
 *            - 6 start_column_addr > 0x7F
 *            - 7 end_column_addr > 0x7F
 * @note      start_page <= 5, end_page <= 5, start_column_addr <= 0x7F, end_column_addr <= 0x7F
 */
uint8_t ssd1315_set_left_horizontal_scroll_one_column(ssd1315_handle_t *handle, uint8_t start_page, uint8_t end_page,
                                                      uint8_t start_column_addr, uint8_t end_column_addr);

/**
 * @}
 */

/**
 * @defgroup ssd1315_extend_driver ssd1315 extend driver function
 * @brief    ssd1315 extend driver modules
 * @ingroup  ssd1315_driver
 * @{
 */

/**
 * @brief     write the register command
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] *buf pointer to a data buffer
 * @param[in] len data length
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_write_cmd(ssd1315_handle_t *handle, uint8_t *buf, uint8_t len);

/**
 * @brief     write the register data
 * @param[in] *handle pointer to an ssd1315 handle structure
 * @param[in] *buf pointer to a data buffer
 * @param[in] len data length
 * @return    status code
 *            - 0 success
 *            - 1 write failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t ssd1315_write_data(ssd1315_handle_t *handle, uint8_t *buf, uint8_t len);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
