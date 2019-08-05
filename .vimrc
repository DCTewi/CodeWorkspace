" Vim Configuration File
" Author: dctewi@dctewi.com
" Description: For minimal icpc use
"
" Properties
set nocompatible
set mouse=a
set encoding=utf-8
set t_Co=256
filetype indent on

" Util
set noswapfile
set noerrorbells
set autoread

" Indent
set cindent
set tabstop=4
set shiftwidth=4
set expandtab
set softtabstop=4

" Layout
syntax on
set number
set cursorline
set showmatch
hi MatchParen cterm=bold ctermbg=none ctermfg=blue

" Search
set hlsearch
set incsearch
set ignorecase

" Map
imap <F8> <ESC>:w<CR>i
map <F5> :w <CR> :!g++ % -o %<.exe -std=c++14 -O2 -Wall -DDEBUG && ./%<.exe <CR>
map <C-F5> :w <CR> :!python3 % <CR>
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap { {}<ESC>i
inoremap {<CR> {<CR>}<ESC>O
inoremap ' ''<ESC>i
inoremap " ""<ESC>i

