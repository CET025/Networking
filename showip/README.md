# showip

O inicio da minha aprendizagem de `Network Programing`.
O objetivo é visualizar que tipo Protocolo que certo site utiliza. (IPv4 || IPv6)
Sendo que grande parte da internet utiliza IPv4.
Este programa utiliza a sys call `getaddrinfo()`.
Mais info:
```bash
man getaddrinfo
```

## Requisitos

- `getaddrinfo()` é uma sys call the UNIX presente em Linux e MACOS,
    ainda não testei no windows, mas quase the certeza que não irá funcionar.
- Malta do windows pode sempre instalar o WSL (https://learn.microsoft.com/en-us/windows/wsl/install)
- Compilador C (por exemplo `gcc`)

## Compilar

```bash
gcc showip.c -o showip
```

## Executar

```bash
./showip www.google.com
```
