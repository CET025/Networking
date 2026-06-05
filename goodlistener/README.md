# goodlistener

- Este programa cria um servidor TCP simples que listen() em `localhost` na porta `8080` e fica em loop a espera de novas conexões.

- Após executar, o browser consegue establecer conexão apesar de não existir troca de info.
- É imprimido para o terminal o valor do novo socket descriptor e o antigo continua a espera de novas conexões.

-   getaddrinfo();
        |
    socket();
        |
    bind();
        |
    listen();
        |
    accept();

## Compilar

```bash
gcc goodlistener.c -o goodlistener
```

## Executar

```bash
./goodlistener
```

- ctrl + C ou D para terminal o processo.

