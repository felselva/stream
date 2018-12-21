/*
Copyright © 2018 Felipe Ferreira da Silva

This software is provided 'as-is', without any express or implied warranty. In
no event will the authors be held liable for any damages arising from the use of
this software.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter it and redistribute it freely, subject to
the following restrictions:

  1. The origin of this software must not be misrepresented; you must not claim
     that you wrote the original software. If you use this software in a
     product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef STREAM_H
#define STREAM_H

#include <stdint.h>
#include <stdio.h>

#define STREAM_VERSION 201812200

enum file_mode {
	FILE_MODE_READ,
	FILE_MODE_WRITE,
	FILE_MODE_READ_AND_WRITE
};

struct file {
	FILE *file;
	uint32_t size;
};

uint8_t memory_compare(uint8_t *pointer0, uint8_t *pointer1, uint32_t size);
void memory_copy(void *destination, void *source, uint32_t size);
void memory_zero(void *pointer, uint32_t size);
void memory_free(void *pointer);
void *memory_reallocate(void *pointer, uint32_t size);
void *memory_allocate(uint32_t size);
uint32_t file_read(struct file *file, void *p, uint32_t size);
uint8_t file_read_uint8(struct file *file, uint8_t *p);
uint8_t file_read_uint16(struct file *file, uint16_t *p);
uint8_t file_read_uint32(struct file *file, uint32_t *p);
uint8_t file_read_uint64(struct file *file, uint64_t *p);
uint8_t file_read_int8(struct file *file, int8_t *p);
uint8_t file_read_int16(struct file *file, int16_t *p);
uint8_t file_read_int32(struct file *file, int32_t *p);
uint8_t file_read_int64(struct file *file, int64_t *p);
uint8_t file_write(struct file *file, void *p, uint32_t size);
uint8_t file_write_uint8(struct file *file, uint8_t p);
uint8_t file_write_uint16(struct file *file, uint16_t p);
uint8_t file_write_uint32(struct file *file, uint32_t p);
uint8_t file_write_uint64(struct file *file, uint64_t p);
uint8_t file_write_int8(struct file *file, int8_t p);
uint8_t file_write_int16(struct file *file, int16_t p);
uint8_t file_write_int32(struct file *file, int32_t p);
uint8_t file_write_int64(struct file *file, int64_t p);
uint32_t file_position(struct file *file);
void file_seek(struct file *file, uint32_t position);
uint8_t file_open(struct file *file, uint8_t *file_name, uint8_t mode);
void file_close(struct file *file);

#endif
