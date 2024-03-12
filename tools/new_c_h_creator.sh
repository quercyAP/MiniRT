#!/bin/bash

projectname="minirt"
srcdir="./src/"
includesdir="./includes/"





dirname=$1
filename=$2
len=${#filename}
if [ ! -d "$srcdir$dirname" ]; then
  mkdir -p $srcdir$dirname
fi
if [ ! -d "$includesdir$dirname" ]; then
  mkdir -p $includesdir$dirname
fi




# Fait le .c
if [ -e "$srcdir$dirname/$filename.c" ]; then
  echo "Le fichier $filename.c existe déjà"
else
    echo -n "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   " >> "$srcdir$dirname/$filename.c"
echo -n "$filename.c" >> "$srcdir$dirname/$filename.c"
i=0
while [ $i -le $(expr 48 - $len) ]
do
echo -n ' ' >> "$srcdir$dirname/$filename.c"
i=$((i+1))
done
echo ":+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/23 09:40:43 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
" >> "$srcdir$dirname/$filename.c"
  echo "#include \"$projectname.h\"
" >> "$srcdir$dirname/$filename.c"
  echo "Le fichier $filename.c a été créé avec succès"
fi





# Fait le .h
if [ -e "$includesdir$dirname/$filename.h" ]; then
  echo "Le fichier $filename.h existe déjà"
else
  echo -n "/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   " >> "$includesdir$dirname/$filename.h"
echo -n "$filename.h" >> "$includesdir$dirname/$filename.h"
i=0
while [ $i -le $(expr 48 - $len) ]
do
echo -n ' ' >> "$includesdir$dirname/$filename.h"
i=$((i+1))
done
echo ":+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/23 09:40:43 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
" >> "$includesdir$dirname/$filename.h"
echo "#ifndef $(echo "$filename" | tr '[:lower:]' '[:upper:]')_H" >> "$includesdir$dirname/$filename.h"
echo "# define $(echo "$filename" | tr '[:lower:]' '[:upper:]')_H
" >> "$includesdir$dirname/$filename.h"
echo "#endif" >> "$includesdir$dirname/$filename.h"
echo "Le fichier $filename.h a été créé avec succès"
fi
