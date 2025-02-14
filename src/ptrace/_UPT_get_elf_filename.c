/*
 * This file is part of libunwind.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "_UPT_internal.h"

int
_UPT_get_elf_filename (unw_addr_space_t as, unw_word_t ip,
                       char *buf, size_t buf_len, unw_word_t *offp, void *arg)
{
  struct UPT_info *ui = arg;

#if UNW_ELF_CLASS == UNW_ELFCLASS64
  return _Uelf64_get_elf_filename (as, ui->pid, ip, buf, buf_len, offp, arg);
#elif UNW_ELF_CLASS == UNW_ELFCLASS32
  return _Uelf32_get_elf_filename (as, ui->pid, ip, buf, buf_len, offp, arg);
#else
  return -UNW_ENOINFO;
#endif
}
