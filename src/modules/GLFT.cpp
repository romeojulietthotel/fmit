// Copyright 2004 "Gilles Degottex"

// This file is part of "fmit"

// "fmit" is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// "fmit" is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

// TODO zoom with a rectangle

#include "GLFT.h"

static const unsigned char g_icon_FT[] = {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
	0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20,
	0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 0x7a, 0x7a, 0xf4, 0x00, 0x00, 0x06,
	0x77, 0x49, 0x44, 0x41, 0x54, 0x58, 0x85, 0xb5, 0x97, 0x6b, 0x6c, 0x9b,
	0x57, 0x19, 0xc7, 0x7f, 0xe7, 0xf5, 0xe5, 0x75, 0xec, 0xdc, 0xec, 0xdc,
	0x5a, 0x27, 0x69, 0x9c, 0x5b, 0xd3, 0xac, 0x6d, 0xda, 0xa8, 0x59, 0x27,
	0x51, 0x79, 0x43, 0x30, 0x09, 0x56, 0x90, 0xcb, 0x84, 0x26, 0x04, 0x15,
	0x6c, 0x1f, 0x80, 0x08, 0x89, 0x0f, 0xa8, 0x20, 0x4d, 0x9a, 0x26, 0xa1,
	0xed, 0x0b, 0xda, 0x47, 0xd6, 0x0f, 0x93, 0x25, 0x10, 0xeb, 0xb6, 0x0a,
	0x06, 0xa2, 0x13, 0x06, 0x15, 0x16, 0x28, 0x2c, 0x58, 0x29, 0xbb, 0xa4,
	0x4b, 0xda, 0xa6, 0x49, 0xb3, 0xdc, 0x1a, 0xc7, 0x4d, 0x9a, 0xe6, 0x1e,
	0xdb, 0x89, 0xef, 0x87, 0x0f, 0xf6, 0xeb, 0xbc, 0x71, 0xec, 0xad, 0x0c,
	0xf5, 0x2f, 0x1d, 0xbd, 0xe7, 0x7d, 0x7c, 0xce, 0xf3, 0xff, 0xbf, 0xcf,
	0xf3, 0x9c, 0xe3, 0x73, 0x04, 0x0f, 0x01, 0x6e, 0x4f, 0xaf, 0x05, 0xd8,
	0x07, 0x54, 0x01, 0x95, 0xc0, 0x1a, 0x30, 0xe4, 0xf7, 0x79, 0x65, 0xfe,
	0x58, 0xf1, 0x39, 0x9c, 0x2b, 0x40, 0x3d, 0xd0, 0x0c, 0xb8, 0x80, 0x03,
	0x40, 0x43, 0xd6, 0xd6, 0x90, 0x6d, 0x55, 0x05, 0x7c, 0x8f, 0x00, 0x67,
	0xfc, 0x3e, 0xef, 0xb4, 0xde, 0x68, 0x2c, 0x42, 0x62, 0x07, 0xda, 0xb3,
	0x24, 0x5a, 0x73, 0x65, 0x9f, 0x4d, 0x80, 0xb9, 0x98, 0x40, 0xd5, 0x6c,
	0xa6, 0xd4, 0x56, 0x82, 0xcd, 0x56, 0x42, 0xa9, 0xb5, 0x04, 0xd5, 0x6c,
	0x62, 0x7c, 0x2a, 0xc0, 0xd6, 0x76, 0xf4, 0x08, 0x70, 0x0e, 0xf8, 0x71,
	0x41, 0x01, 0x6e, 0x4f, 0xaf, 0x0d, 0xf8, 0x29, 0x70, 0x36, 0x4b, 0x2e,
	0x00, 0x0c, 0x06, 0x85, 0xba, 0x1a, 0x07, 0x35, 0x0e, 0x3b, 0x95, 0x15,
	0xa5, 0x54, 0x56, 0x94, 0x61, 0xaf, 0x28, 0xcb, 0x3d, 0x2b, 0x2a, 0xca,
	0xb0, 0xd9, 0x6c, 0x58, 0xad, 0x36, 0x4c, 0xaa, 0x85, 0x94, 0x54, 0x88,
	0x25, 0xd2, 0xa4, 0x25, 0x18, 0x15, 0x41, 0x53, 0x8d, 0xca, 0xe5, 0x2b,
	0x03, 0xbc, 0x72, 0xfe, 0x4d, 0xb2, 0x1f, 0xc0, 0x1e, 0x01, 0x59, 0xf2,
	0x01, 0xe0, 0x98, 0xa2, 0x28, 0x9c, 0x7a, 0xf4, 0x28, 0x5f, 0x38, 0xd9,
	0x45, 0x57, 0x67, 0x1b, 0xfb, 0xea, 0xaa, 0x49, 0xa4, 0x04, 0x5b, 0xb1,
	0x14, 0x91, 0x58, 0x9a, 0xad, 0x78, 0x9a, 0xad, 0x98, 0xd6, 0x52, 0xcc,
	0x6e, 0xa5, 0x49, 0x85, 0x25, 0x92, 0x14, 0x52, 0x46, 0x90, 0x12, 0x24,
	0x20, 0xa5, 0x44, 0x4a, 0x70, 0x94, 0x19, 0x39, 0xd8, 0x72, 0x40, 0xe3,
	0x6b, 0x2c, 0x28, 0x00, 0xf8, 0x01, 0x70, 0xcc, 0xa0, 0x28, 0x9c, 0xff,
	0xc5, 0xcf, 0x38, 0xd8, 0xd6, 0xcc, 0x9d, 0xfb, 0x31, 0x02, 0x9b, 0x09,
	0xc6, 0x96, 0xc3, 0xa4, 0xd3, 0x32, 0xeb, 0x58, 0xea, 0x08, 0x32, 0x4d,
	0x51, 0x04, 0x42, 0xb0, 0xdb, 0xae, 0xfb, 0x3d, 0x1c, 0x4d, 0xe1, 0xb0,
	0x97, 0x6b, 0x7c, 0xad, 0x6e, 0x4f, 0xaf, 0xd0, 0x17, 0xa3, 0x26, 0xa0,
	0x05, 0xe0, 0x50, 0x7b, 0x13, 0x1d, 0x6d, 0xcd, 0x0c, 0x4e, 0x87, 0x89,
	0xc6, 0x33, 0x61, 0x34, 0x28, 0xa0, 0x08, 0xb1, 0xc7, 0x71, 0xee, 0x2b,
	0x01, 0x29, 0xc5, 0x2e, 0x3b, 0x40, 0x5a, 0x02, 0x12, 0x62, 0x71, 0xc9,
	0xfe, 0xda, 0x72, 0x2c, 0xaa, 0x99, 0x68, 0x2c, 0x6e, 0x05, 0x9c, 0xc0,
	0x5d, 0x4d, 0x80, 0xa2, 0x17, 0xb2, 0xaf, 0xae, 0x9a, 0xf9, 0xb5, 0x38,
	0xc9, 0x54, 0x26, 0x7f, 0xb9, 0x66, 0x10, 0x18, 0x0d, 0xe8, 0xfa, 0x3a,
	0x7b, 0xa1, 0x31, 0xca, 0xce, 0xfc, 0x58, 0x32, 0x8d, 0x10, 0x82, 0x06,
	0x67, 0xad, 0xc6, 0xd9, 0xa1, 0x4f, 0x81, 0xa2, 0x7f, 0xb1, 0x5a, 0x54,
	0x92, 0x29, 0x99, 0x71, 0x64, 0xd0, 0x93, 0xb1, 0x97, 0xb8, 0x98, 0xa0,
	0xbc, 0xb9, 0x89, 0x64, 0x26, 0x26, 0xae, 0xc6, 0xfd, 0x1a, 0x4d, 0x67,
	0xa1, 0x1a, 0x88, 0x03, 0x58, 0x54, 0x73, 0x6e, 0x22, 0x32, 0x1b, 0xc6,
	0x3d, 0x61, 0x2f, 0x9e, 0xef, 0x42, 0x29, 0x48, 0x66, 0x9d, 0xb4, 0x34,
	0x39, 0x35, 0xce, 0x43, 0x85, 0x04, 0x6c, 0x02, 0xa4, 0xd2, 0x69, 0x4c,
	0xc6, 0xcc, 0xd7, 0xec, 0x12, 0x50, 0x28, 0xf7, 0x52, 0x14, 0x16, 0x24,
	0xf5, 0x02, 0x24, 0x26, 0x43, 0x26, 0xc8, 0xcd, 0x07, 0xea, 0x3f, 0x5b,
	0x40, 0x3c, 0x9e, 0xc0, 0x6c, 0x54, 0x74, 0x11, 0x90, 0x40, 0xb1, 0x02,
	0xcc, 0xef, 0x4b, 0x64, 0x76, 0x2c, 0x40, 0x79, 0x89, 0x81, 0xfa, 0x2a,
	0x33, 0x8e, 0xd2, 0x0c, 0x45, 0xf3, 0x83, 0x44, 0x20, 0x9e, 0x48, 0x62,
	0xca, 0xa6, 0xe0, 0xb7, 0xaf, 0xbf, 0xc3, 0x5c, 0x60, 0x01, 0x00, 0x83,
	0xc1, 0x40, 0xeb, 0x41, 0x17, 0x5f, 0x7e, 0xea, 0x71, 0x54, 0x55, 0x45,
	0x4a, 0xc1, 0xf5, 0xa1, 0x51, 0xae, 0xfc, 0xb5, 0x3f, 0x17, 0x72, 0x8d,
	0xd8, 0xfd, 0x78, 0x37, 0xd1, 0x8d, 0x55, 0x82, 0x81, 0x79, 0x3d, 0x0f,
	0x52, 0x42, 0x70, 0x62, 0x91, 0x86, 0xf6, 0xba, 0x7a, 0xb7, 0xa7, 0xb7,
	0xcc, 0xef, 0xf3, 0x86, 0xf4, 0x02, 0x96, 0x01, 0x22, 0x91, 0x6d, 0x4c,
	0x06, 0x81, 0x90, 0x69, 0x5e, 0xfb, 0xe5, 0x1b, 0x84, 0x42, 0x61, 0xaa,
	0xab, 0x1d, 0x6c, 0x6f, 0x47, 0x59, 0x5d, 0x59, 0xe7, 0xe4, 0xef, 0x2f,
	0xf3, 0xda, 0x85, 0x57, 0x30, 0xab, 0x2a, 0x57, 0x2e, 0xbf, 0xc7, 0x9b,
	0xbf, 0xfe, 0x03, 0x35, 0xb5, 0x55, 0x28, 0x06, 0x05, 0x45, 0x08, 0x0c,
	0x0a, 0x7c, 0xe5, 0x89, 0x47, 0xf8, 0xcd, 0xc5, 0xcb, 0xcc, 0xcf, 0x2f,
	0xb1, 0xb1, 0x11, 0x61, 0x73, 0x33, 0x42, 0x6d, 0xad, 0x1d, 0x55, 0x35,
	0x21, 0x0d, 0x02, 0x32, 0x3b, 0xec, 0x21, 0xe0, 0x23, 0xd8, 0x59, 0x05,
	0xf7, 0x01, 0x36, 0x42, 0x11, 0x8c, 0x06, 0xc1, 0xf2, 0xe2, 0x32, 0xcb,
	0x4b, 0xab, 0x9c, 0xf6, 0x7c, 0x89, 0xbf, 0x0f, 0x5c, 0xe4, 0x5f, 0x1f,
	0xbc, 0xcd, 0xd9, 0xe7, 0xbe, 0xc1, 0x87, 0xff, 0x19, 0xa6, 0xff, 0x1f,
	0x57, 0x31, 0x1a, 0x04, 0xa3, 0x37, 0xc7, 0x29, 0xaf, 0x28, 0xe5, 0x9f,
	0x03, 0x17, 0x98, 0x9c, 0xbc, 0xc4, 0xcc, 0xf4, 0x25, 0x26, 0x27, 0x2f,
	0x71, 0xf6, 0xec, 0x57, 0xe9, 0xef, 0xf7, 0x32, 0x31, 0x71, 0x89, 0xa7,
	0x9f, 0xfe, 0x22, 0x40, 0xee, 0xfd, 0x47, 0x3f, 0xf9, 0xa6, 0x16, 0x90,
	0xc3, 0x5a, 0x47, 0x13, 0xb0, 0x04, 0xb0, 0x19, 0x8e, 0x60, 0x34, 0xc0,
	0xe8, 0xc8, 0x38, 0x00, 0xdd, 0xdd, 0x9d, 0x58, 0x4b, 0xcc, 0x94, 0x97,
	0x59, 0xf9, 0xd6, 0x77, 0xbe, 0x06, 0xc0, 0x8d, 0xa1, 0x51, 0xe2, 0xb1,
	0x28, 0x33, 0x53, 0x01, 0x5a, 0x5b, 0x1b, 0x38, 0x50, 0x6b, 0x25, 0x9d,
	0x4c, 0x10, 0x8b, 0xc5, 0x49, 0x26, 0x53, 0x28, 0x8a, 0x82, 0xaa, 0x9a,
	0x51, 0x55, 0x33, 0xc3, 0xc3, 0x9f, 0x50, 0x5b, 0x6b, 0xa7, 0xb5, 0xb5,
	0x01, 0x55, 0x35, 0xeb, 0xb7, 0xe4, 0x23, 0xf9, 0x35, 0x90, 0x89, 0xc0,
	0x46, 0x18, 0x45, 0x08, 0x46, 0xae, 0x67, 0x04, 0x1c, 0xeb, 0xee, 0xc0,
	0xa8, 0x08, 0x24, 0x12, 0xd5, 0x9c, 0x19, 0x9a, 0x4e, 0x25, 0x89, 0xad,
	0x2f, 0xb3, 0xb6, 0xba, 0x4e, 0x68, 0x33, 0x84, 0xcb, 0x75, 0x26, 0x97,
	0xe7, 0xd3, 0xa7, 0x4f, 0xf1, 0xd6, 0x5b, 0x2f, 0xa3, 0xf9, 0x9a, 0x98,
	0x08, 0x70, 0xea, 0xd4, 0x31, 0x4c, 0xa6, 0xcc, 0xdc, 0x96, 0xa6, 0xdc,
	0x4a, 0xd8, 0x2d, 0xc0, 0xef, 0xf3, 0xae, 0xb9, 0x3d, 0xbd, 0x91, 0x8d,
	0x50, 0xd8, 0x16, 0x8b, 0x27, 0xb8, 0x39, 0x7c, 0x1b, 0x55, 0x35, 0x73,
	0xf4, 0x48, 0x2b, 0x46, 0xa3, 0x40, 0x4a, 0xc1, 0xed, 0xd1, 0x29, 0x00,
	0xba, 0x0e, 0x37, 0x31, 0x36, 0xf2, 0x09, 0x52, 0xc2, 0x33, 0xcf, 0x3c,
	0xc9, 0xe1, 0xc3, 0x2d, 0x39, 0x01, 0x8f, 0x3d, 0x96, 0x8b, 0x2c, 0xb7,
	0x6e, 0x4d, 0xb3, 0xbd, 0x1d, 0xa3, 0xa7, 0x67, 0x67, 0xdf, 0x69, 0x71,
	0x15, 0x11, 0x90, 0x45, 0x10, 0xe8, 0xb8, 0xb7, 0xb8, 0xcc, 0x8d, 0xeb,
	0xe3, 0xb4, 0x1f, 0x6c, 0xa2, 0xb2, 0xc2, 0x46, 0x5a, 0xc2, 0x76, 0x34,
	0xc6, 0xeb, 0xbf, 0xfa, 0x23, 0x16, 0x8b, 0xca, 0x19, 0x8f, 0x9b, 0x57,
	0x5f, 0x7d, 0x1b, 0x21, 0xe0, 0xf9, 0xe7, 0xbf, 0x47, 0x57, 0x57, 0x3b,
	0x85, 0x70, 0xed, 0xda, 0x18, 0x52, 0x42, 0x4f, 0xcf, 0x23, 0x39, 0x5b,
	0x65, 0x79, 0x29, 0x55, 0xf6, 0x0a, 0x56, 0xd6, 0x36, 0xea, 0xdd, 0x9e,
	0x5e, 0xbb, 0xdf, 0xe7, 0x5d, 0xd3, 0x6f, 0xc5, 0x73, 0x00, 0xc3, 0x37,
	0x27, 0x58, 0x5d, 0xdd, 0xc4, 0xe9, 0xac, 0x61, 0xf8, 0xe3, 0x51, 0xde,
	0xbb, 0xf2, 0x3e, 0xdf, 0x7f, 0xf6, 0x45, 0x86, 0x3e, 0x1e, 0xe3, 0xdc,
	0xb9, 0x6f, 0xd3, 0xd6, 0xd6, 0xc8, 0xe0, 0xe0, 0x18, 0x0e, 0x47, 0x05,
	0x2d, 0x2d, 0xf5, 0xf9, 0xbc, 0x39, 0x0c, 0x0e, 0x8e, 0x21, 0x04, 0x9c,
	0x38, 0xb1, 0x6b, 0xd9, 0xe3, 0x3a, 0x90, 0xdb, 0x92, 0x8f, 0xe4, 0x47,
	0x60, 0x0e, 0xe0, 0x83, 0xf7, 0x47, 0x00, 0xe8, 0x7b, 0xf7, 0x2a, 0x7d,
	0xef, 0x5e, 0x45, 0x08, 0x81, 0xdd, 0x5e, 0xc6, 0x4b, 0x2f, 0xfd, 0x90,
	0x17, 0x5e, 0x78, 0x8e, 0x50, 0x28, 0xc2, 0xf8, 0xf8, 0x2c, 0x9d, 0x9d,
	0x2e, 0x4a, 0x4b, 0xad, 0x9f, 0x2a, 0x60, 0xff, 0xfe, 0x6a, 0x9c, 0xce,
	0x9a, 0x5d, 0xf6, 0x46, 0x67, 0x2d, 0xd7, 0xae, 0xdf, 0x06, 0x38, 0x0a,
	0xf8, 0xf3, 0x53, 0x80, 0xb3, 0xb1, 0x86, 0x0f, 0x3f, 0xba, 0x90, 0x3b,
	0x03, 0x94, 0x94, 0xa8, 0xb4, 0xb5, 0x3a, 0xb1, 0xd9, 0x4a, 0x00, 0xb0,
	0x58, 0xa0, 0xaf, 0xef, 0x3c, 0x0e, 0x47, 0x39, 0xc5, 0x20, 0xa5, 0xe4,
	0xe2, 0xc5, 0x97, 0x51, 0x55, 0x73, 0xae, 0x00, 0x35, 0x34, 0x38, 0xeb,
	0xb4, 0xee, 0xf1, 0x82, 0x11, 0x88, 0x25, 0x13, 0x3c, 0xda, 0xd3, 0x99,
	0xdb, 0x66, 0x95, 0xbc, 0xa3, 0xa5, 0xc9, 0x64, 0xe4, 0xc4, 0x89, 0x4e,
	0x3e, 0x0d, 0x42, 0x08, 0x8e, 0x1f, 0xef, 0x28, 0xf8, 0x5b, 0xe3, 0xce,
	0xdf, 0x72, 0x77, 0x41, 0x01, 0x8b, 0x4b, 0xab, 0x59, 0x27, 0x9f, 0xe3,
	0xc8, 0xfc, 0x00, 0xa8, 0xa9, 0xb2, 0x6b, 0xdd, 0x2e, 0xb7, 0xa7, 0xd7,
	0xaa, 0x2f, 0xc2, 0x00, 0xc0, 0x6c, 0xf0, 0xde, 0x43, 0xa0, 0xdd, 0x81,
	0xaa, 0x9a, 0xb4, 0xae, 0x19, 0x68, 0xd6, 0x0b, 0x98, 0x06, 0xd2, 0xf7,
	0xee, 0xaf, 0x10, 0x8b, 0xc5, 0x1f, 0x0a, 0xf9, 0x76, 0x34, 0xc6, 0x5f,
	0xfa, 0x06, 0xf4, 0xa6, 0xf5, 0x5c, 0x0a, 0xfc, 0x3e, 0x6f, 0xd4, 0xed,
	0xe9, 0x0d, 0x48, 0x29, 0x5d, 0x81, 0xbb, 0x8b, 0xb4, 0xb7, 0xec, 0x39,
	0xc0, 0xfe, 0x4f, 0x58, 0x5a, 0x59, 0x67, 0x72, 0x26, 0xc8, 0xe4, 0xcc,
	0x1c, 0x93, 0x77, 0x82, 0x4c, 0xce, 0x04, 0xb9, 0xbb, 0x70, 0x9f, 0xb4,
	0x76, 0xc8, 0x80, 0x3f, 0xfb, 0x7d, 0xde, 0xbb, 0xf9, 0x17, 0x93, 0x31,
	0xc0, 0x35, 0x3b, 0xb7, 0xf0, 0xc0, 0x02, 0x92, 0xc9, 0x14, 0xb3, 0xc1,
	0x7b, 0x19, 0xb2, 0x3b, 0x73, 0x59, 0xd2, 0x20, 0x1b, 0x9b, 0xe1, 0x62,
	0x53, 0x66, 0x81, 0x77, 0x80, 0x9f, 0xc3, 0xde, 0x9b, 0xd1, 0x35, 0xe0,
	0xa9, 0xf1, 0xa9, 0x00, 0x4f, 0x3e, 0x71, 0x72, 0xcf, 0xcc, 0x50, 0x78,
	0x6b, 0x0f, 0xd1, 0x9d, 0xb9, 0x05, 0x12, 0x89, 0x64, 0x21, 0xa2, 0x34,
	0x30, 0x05, 0xdc, 0x04, 0x86, 0x81, 0x21, 0x60, 0xd0, 0xef, 0xf3, 0xee,
	0x2a, 0xb2, 0x7c, 0x01, 0xfd, 0xc0, 0x8b, 0x7f, 0xfa, 0xdb, 0xbf, 0xb1,
	0x96, 0x58, 0x28, 0x2f, 0xb3, 0xb1, 0xb2, 0xb6, 0xc1, 0x4c, 0x60, 0x9e,
	0xc9, 0x99, 0x60, 0x6e, 0x85, 0x14, 0xc0, 0x0a, 0x99, 0xbb, 0xdf, 0x8d,
	0x2c, 0xe1, 0x0d, 0x60, 0xc4, 0xef, 0xf3, 0x46, 0x8a, 0x4d, 0xd0, 0xb0,
	0x67, 0xa5, 0xb9, 0x3d, 0xbd, 0x6f, 0x00, 0xdf, 0x2d, 0x32, 0x3e, 0x04,
	0x8c, 0x66, 0xc9, 0x6e, 0x65, 0x9f, 0x23, 0x7e, 0x9f, 0x77, 0xe1, 0xb3,
	0x88, 0x8a, 0xa1, 0xd0, 0xe5, 0xf4, 0x59, 0xe0, 0x77, 0xc0, 0xd7, 0x81,
	0x52, 0x1d, 0xe1, 0x08, 0x30, 0x5b, 0xe8, 0x8a, 0xfd, 0xff, 0xe0, 0xbf,
	0x87, 0xf6, 0xdb, 0x8f, 0xf0, 0x17, 0xa5, 0xe8, 0x00, 0x00, 0x00, 0x00,
	0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};

#include <iostream>
using namespace std;
#include <qtooltip.h>
#include <qimage.h>
#include <qevent.h>
#include <qboxlayout.h>
#include <qwidgetaction.h>
#include <GL/glut.h>
#include <Music/Music.h>
#include <Music/SPWindow.h>
using namespace Music;
#include <CppAddons/CAMath.h>
using namespace Math;

GLFT::GLFT(QWidget* parent)
: QGLWidget(parent)
, View(tr("Fourier Transform"), this)
, m_components_max(1.0)
{
	m_start_move_mouse = true;

	m_os = 2;					// over sampling factor

	// settings
	QPixmap img;
	img.loadFromData(g_icon_FT, sizeof(g_icon_FT), "PNG");
	setting_show->setIcon(QIcon(img));
	setting_show->setChecked(false);
	hide();

	setting_db_scale = new QAction(tr("dB scale"), this);
	setting_db_scale->setCheckable(true);
	connect(setting_db_scale, SIGNAL(toggled(bool)), this, SLOT(dBScaleChanged(bool)));
	setting_db_scale->setChecked(true);
	m_popup_menu.addAction(setting_db_scale);
	resetaxis();

	QHBoxLayout* sizeActionLayout = new QHBoxLayout(&m_popup_menu);

	QLabel* sizeActionTitle = new QLabel(tr("Size"), &m_popup_menu);
	sizeActionLayout->addWidget(sizeActionTitle);

	setting_winlen = new QSpinBox(&m_popup_menu);
	setting_winlen->setObjectName("setting_winlen");
	setting_winlen->setMinimum(1);
	setting_winlen->setMaximum(1000);
	setting_winlen->setSingleStep(1);
	setting_winlen->setValue(20);
	setting_winlen->setSuffix(" ms");
	setting_winlen->setToolTip(tr("window length"));
	connect(setting_winlen, SIGNAL(valueChanged(int)), this, SLOT(spinWinLengthChanged(int)));
	sizeActionLayout->addWidget(setting_winlen);

	QWidget* sizeActionWidget = new QWidget(&m_popup_menu);
	sizeActionWidget->setLayout(sizeActionLayout);

	QWidgetAction* sizeAction = new QWidgetAction(&m_popup_menu);
	sizeAction->setDefaultWidget(sizeActionWidget);
	m_popup_menu.addAction(sizeAction);

	QWidgetAction* helpCaption01 = new QWidgetAction(&m_popup_menu);
	helpCaption01->setDefaultWidget(new Title(tr("- Press left mouse button to move the view"), &m_popup_menu));
	m_popup_menu.addAction(helpCaption01);
	QWidgetAction* helpCaption02 = new QWidgetAction(&m_popup_menu);
	helpCaption02->setDefaultWidget(new Title(tr("- Press SHIFT key and left mouse button to zoom in and out"), &m_popup_menu));
	m_popup_menu.addAction(helpCaption02);
	QWidgetAction* helpCaption03 = new QWidgetAction(&m_popup_menu);
	helpCaption03->setDefaultWidget(new Title(tr("- Double-click to reset the view"), &m_popup_menu));
	m_popup_menu.addAction(helpCaption03);

	s_settings->add(setting_winlen);

	spinWinLengthChanged(setting_winlen->value());
}

void GLFT::refreshGraph()
{
	while(int(buff.size())>m_plan.size())
		buff.pop_back();
}

void GLFT::setSamplingRate(int sr)
{
	m_maxf=sr/2;
}

void GLFT::resetaxis()
{
	m_minf=0;
	m_maxf=Music::GetSamplingRate()/2; // sr is surely -1 because not yet defined

	if(setting_db_scale->isChecked())
	{
		m_minA = -50; // [dB]
		m_maxA = 100; // [dB]
	}
	else
	{
		m_maxA = 1; // [amplitude]
	}
}
void GLFT::dBScaleChanged(bool db)
{
	resetaxis();
	update();
}

void GLFT::spinWinLengthChanged(int num)
{
	if(Music::GetSamplingRate()>0)
	{
		// Create window
		int winlen = int(num/1000.0*Music::GetSamplingRate());
		win = hann(winlen);
		double win_sum = 0.0;
		// normalize the window in energy
		for(size_t i=0; i<win.size(); i++)
			win_sum += win[i];
		for(size_t i=0; i<win.size(); i++)
			win[i] *= 2*win.size()/win_sum; // 2* because the positive freq are half of the energy

		// Create FFTW3 plan
		int fftlen=1;
		while(fftlen<winlen) fftlen *= 2;
		fftlen *= pow(2,m_os);
		assert(fftlen<int(Music::GetSamplingRate()));
		m_plan.resize(fftlen);
		m_components.resize(m_plan.size()/2);

        cout << "GLFT: INFO: window length=" << win.size() << "ms FFT length=" << m_plan.size() << endl;
	}
}

void GLFT::initializeGL()
{
	// Set the clear color to black
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glShadeModel( GL_FLAT );
//	glShadeModel( GL_SMOOTH );

	glLoadIdentity();
}

void GLFT::mousePressEvent(QMouseEvent* e)
{
	m_start_move_mouse = true;
	m_press_x = e->x();
	m_press_y = e->y();
	m_press_minf = m_minf;
	m_press_maxf = m_maxf;

	double f = (m_maxf-m_minf)*double(m_press_x)/width()+m_minf;
	m_text = tr("Frequency %1 [Hz]").arg(f);
	updateGL();
}
void GLFT::mouseDoubleClickEvent(QMouseEvent* e)
{
	m_start_move_mouse = true;
	m_minf=0;
	m_maxf=Music::GetSamplingRate()/2; // sr is surely -1 because not yet defined
	resetaxis();
	updateGL();
}
void GLFT::mouseMoveEvent(QMouseEvent* e)
{
	static int old_x;
	static int old_y;
	if(m_start_move_mouse)
	{
		old_x = e->x();
		old_y = e->y();
		m_start_move_mouse = false;
	}
	int dx = e->x() - old_x;
	int dy = e->y() - old_y;

	if(Qt::LeftButton & e->buttons())
	{
		if(Qt::ShiftModifier & e->modifiers())
		{
			double f = (m_maxf-m_minf)*double(m_press_x)/width()+m_minf;
			double zx = double(m_press_x-e->x())/width();
			zx = pow(8, zx);
			m_minf = f - zx*(f-m_press_minf);
			m_maxf = f + zx*(m_press_maxf-f);
		}
		else
		{
			m_minf -= (m_maxf-m_minf)*dx/width();
			m_maxf -= (m_maxf-m_minf)*dx/width();

			if(setting_db_scale->isChecked())
			{
				m_minA += (m_maxA-m_minA)*dy/height();
				m_maxA += (m_maxA-m_minA)*dy/height();
			}
			else
				m_maxA -= m_maxA*double(dy)/height();
		}

		updateGL();
	}

	old_x = e->x();
	old_y = e->y();
}

void GLFT::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);

	if(win.size()>0 && int(buff.size())>=m_plan.size())
	{
		// Use last samples
		while(int(buff.size())>m_plan.size())
			buff.pop_back();

		int sr = Music::GetSamplingRate();

//		cout << m_plan.size() << endl;

		// name
		string str = tr("Fourier Transform").toStdString();
		glColor3f(0.75,0.75,0.75);
		glRasterPos2i(2, height()-20);
		for(size_t i = 0; i < str.size(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (unsigned char)str[i]);

		for(int i=0; i<int(win.size()); i++)
			m_plan.in[i] = buff[i]*win[i];
		for(int i=win.size(); i<int(m_plan.in.size()); i++)
			m_plan.in[i] = 0.0;

		m_plan.execute();

		for(int i=0; i<int(m_components.size()); i++)
			m_components[i] = mod(m_plan.out[i]);

//		cout << "m_minA=" << m_minA << " m_maxA=" << m_maxA << endl;
		double y;
		glBegin(GL_LINE_STRIP);
		glColor3f(0.4, 0.4, 0.5);
		for(size_t x=0; x<width(); x++)
		{
			int index = int(0.5+(m_minf+(m_maxf-m_minf)*double(x)/width())*m_components.size()/(sr/2.0));
			if(index<0) index=0;
			else if(index>=m_components.size()) index=m_components.size();
			y = m_components[index];
			if(setting_db_scale->isChecked())
				y = height()*(lp(y)-m_minA)/(m_maxA-m_minA);
			else
				y = height()*y*m_maxA;

			glVertex2i(x, int(y));
		}

		glEnd();

		// scale
		/*glColor3f(0,0,0);
		for(size_t i=0; i<m_components.size(); i++)
		{
			glRasterPos2i(int((i+0.5)*step)-3, 2);

//			string str = StringAddons::toString(i+1);
			string str = QString::number(i+1).toStdString();

			for(size_t i = 0; i < str.length(); i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, (unsigned char)str[i]);
		}*/
	}

	// Text
	if(m_text.length()>0)
	{
		glColor3f(0,0,0);
		glRasterPos2i(width()/2, 12);

		string str = m_text.toStdString();

		for(size_t i = 0; i < str.length(); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, (unsigned char)str[i]);
	}

	glFlush();
}

void GLFT::resizeGL( int w, int h )
{
	// Set the new viewport size
	glViewport(0, 0, (GLint)w, (GLint)h);

	// Choose the projection matrix to be the matrix
	// manipulated by the following calls
	glMatrixMode(GL_PROJECTION);

	// Set the projection matrix to be the identity matrix
	glLoadIdentity();

	// Define the dimensions of the Orthographic Viewing Volume
	glOrtho(0.0, w, 0.0, h, 0.0, 1.0);

	// Choose the modelview matrix to be the matrix
	// manipulated by further calls
	glMatrixMode(GL_MODELVIEW);
}
