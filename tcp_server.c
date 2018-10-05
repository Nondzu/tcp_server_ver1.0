/*
 * tcp_server.c
 * 
 * Copyright 2018 kamil <kamil@kamil-VirtualBox>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include "tcp.h"
#include <string.h>
int main(int argc, char **argv)
{
	printf("hello\r\n");
	
	tcp_init(1122);
	
	char tx[]="hello here's server\r\n";
	
	char rx[2000];
	int rx_size;
	while(1)
	{
		memset(rx, 0x00, 2000);
		if(-1==tcp_read(rx, &rx_size))
		{
			printf("close connection\r\n");
			break;
		}
		printf("info from client: %s\r\n", rx);
		tcp_write(tx, (int)strlen(tx));		
	}
	
	printf("END PROGRAM\r\n");
	
	return 0;
}

