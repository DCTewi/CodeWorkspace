" Vim Configuration File
" Author: dctewi@dctewi.com
" Description: For minimal icpc use
"
" Properties
set nocompatible
set showcmd
set mouse=a
set encoding=utf-8
set t_Co=256
set clipboard=unnamedplus
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
set smartcase

" Compile
map <F5> :w <CR> :!g++ "%" -o "%<.exe" -std=c++14 -O2 -Wall -DDEBUG && "./%<.exe" <CR>
map <C-F5> :w <CR> :!python3 % <CR>

" Auto complete
inoremap ( ()<ESC>i
inoremap [ []<ESC>i
inoremap ' ''<ESC>i
inoremap " ""<ESC>i
inoremap { {}<ESC>i
inoremap {<CR> {<CR>}<ESC>O

" Header
inoremap <F8> #include<bits/stdc++.h><CR>using namespace std;<CR>typedef long long ll;<CR>

