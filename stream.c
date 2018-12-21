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

#include "stream.h"
#include <stdlib.h>

uint8_t memory_compare(uint8_t *pointer0, uint8_t *pointer1, uint32_t size)
{
	uint8_t result;
	uint32_t i;
	result = 1;
	i = 0;
	while (i < size && result == 1) {
		if (pointer0[i] != pointer1[i]) {
			result = 0;
		}
		i = i + 1;
	}
	return result;
}

void memory_copy(void *destination, void *source, uint32_t size)
{
	uint32_t i;
	uint8_t *data_destination;
	uint8_t *data_source;
	data_destination = (uint8_t *)destination;
	data_source = (uint8_t *)source;
	i = 0;
	while (i < size) {
		data_destination[i] = data_source[i];
		i = i + 1;
	}
}

void memory_zero(void *pointer, uint32_t size)
{
	uint8_t *data_iterator;
	uint8_t *pointer_end;
	data_iterator = (uint8_t *)pointer;
	pointer_end = (uint8_t *)pointer + size;
	while (data_iterator != pointer_end) {
		data_iterator[0] = 0;
		data_iterator = data_iterator + 1;
	}
}

void memory_free(void *pointer)
{
	free(pointer);
}

void *memory_reallocate(void *pointer, uint32_t size)
{
	void *result;
	result = realloc(pointer, size);
	return result;
}

void *memory_allocate(uint32_t size)
{
	void *result;
	result = malloc(size);
	memory_zero(result, size);
	return result;
}

uint32_t file_read(struct file *file, void *p, uint32_t size)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, size, file->file) != size) {
		success = 0;
	}
	return success;
}

uint8_t file_read_uint8(struct file *file, uint8_t *p)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, sizeof(uint8_t), file->file) != sizeof(uint8_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_read_uint16(struct file *file, uint16_t *p)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, sizeof(uint16_t), file->file) != sizeof(uint16_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_read_uint32(struct file *file, uint32_t *p)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, sizeof(uint32_t), file->file) != sizeof(uint32_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_read_uint64(struct file *file, uint64_t *p)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, sizeof(uint64_t), file->file) != sizeof(uint64_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_read_int8(struct file *file, int8_t *p)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, sizeof(int8_t), file->file) != sizeof(int8_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_read_int16(struct file *file, int16_t *p)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, sizeof(int16_t), file->file) != sizeof(int16_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_read_int32(struct file *file, int32_t *p)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, sizeof(int32_t), file->file) != sizeof(int32_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_read_int64(struct file *file, int64_t *p)
{
	uint8_t success;
	success = 1;
	if (fread(p, 1, sizeof(int64_t), file->file) != sizeof(int64_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_write(struct file *file, void *p, uint32_t size)
{
	uint8_t success;
	success = 1;
	if (fwrite(p, 1, size, file->file) != size) {
		success = 0;
	}
	return success;
}

uint8_t file_write_uint8(struct file *file, uint8_t p)
{
	uint8_t success;
	success = 1;
	if (fwrite(&p, 1, sizeof(uint8_t), file->file) != sizeof(uint8_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_write_uint16(struct file *file, uint16_t p)
{
	uint8_t success;
	success = 1;
	if (fwrite(&p, 1, sizeof(uint16_t), file->file) != sizeof(uint16_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_write_uint32(struct file *file, uint32_t p)
{
	uint8_t success;
	success = 1;
	if (fwrite(&p, 1, sizeof(uint32_t), file->file) != sizeof(uint32_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_write_uint64(struct file *file, uint64_t p)
{
	uint8_t success;
	success = 1;
	if (fwrite(&p, 1, sizeof(uint64_t), file->file) != sizeof(uint64_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_write_int8(struct file *file, int8_t p)
{
	uint8_t success;
	success = 1;
	if (fwrite(&p, 1, sizeof(int8_t), file->file) != sizeof(int8_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_write_int16(struct file *file, int16_t p)
{
	uint8_t success;
	success = 1;
	if (fwrite(&p, 1, sizeof(int16_t), file->file) != sizeof(int16_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_write_int32(struct file *file, int32_t p)
{
	uint8_t success;
	success = 1;
	if (fwrite(&p, 1, sizeof(int32_t), file->file) != sizeof(int32_t)) {
		success = 0;
	}
	return success;
}

uint8_t file_write_int64(struct file *file, int64_t p)
{
	uint8_t success;
	success = 1;
	if (fwrite(&p, 1, sizeof(int64_t), file->file) != sizeof(int64_t)) {
		success = 0;
	}
	return success;
}

uint32_t file_position(struct file *file)
{
	return ftell(file->file);
}

void file_seek(struct file *file, uint32_t position)
{
	fseek(file->file, position, SEEK_SET);
}

uint8_t file_open(struct file *file, uint8_t *file_name, uint8_t mode)
{
	uint8_t success;
	success = 1;
	file->file = NULL;
	if (mode == FILE_MODE_READ) {
		file->file = fopen((char *)file_name, "r");
	} else if (mode == FILE_MODE_WRITE) {
		file->file = fopen((char *)file_name, "w");
	} else if (mode == FILE_MODE_READ_AND_WRITE) {
		file->file = fopen((char *)file_name, "rw");
	}
	if (file->file != NULL) {
		fseek(file->file, 0, SEEK_END);
		file->size = ftell(file->file);
		fseek(file->file, 0, SEEK_SET);
	} else {
		success = 0;
	}
	return success;
}

void file_close(struct file *file)
{
	fclose(file->file);
	file->file = NULL;
}
