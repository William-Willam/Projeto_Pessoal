import express from "express";
import { PrismaClient } from "@prisma/client";

// Criando a instância do Express
const app = express();
app.use(express.json());

// Middleware para interpretar JSON no corpo das requisições
app.use(express.json());

// Simulando um banco de dados em memória
//const usuarios = [];

//Prisma
const prisma = new PrismaClient();

/*
=====================================
 API de Gerenciamento de Usuários
=====================================

Funcionalidades da API:

1) Criar um usuário
2) Listar todos os usuários
3) Editar um usuário (PUT/PATCH)
4) Deletar um usuário

Métodos HTTP utilizados:

- GET:    Recupera a lista de usuários
- POST:   Cria um novo usuário
- PUT:    Edita múltiplas informações de um usuário
- PATCH:  Edita uma informação específica de um usuário
- DELETE: Remove um usuário do sistema

=====================================
 Explicação sobre Requisições HTTP
=====================================

- Query Params: 
  Enviados na URL após o símbolo "?".
  Usados para filtrar ou buscar dados.
  Ex: /usuarios?nome=Lucas&idade=25

- Route Params:
  Parâmetros dinâmicos na rota.
  Ex: /usuarios/:id

- Body Params:
  Corpo da requisição, geralmente em JSON.
  Usado para enviar dados nas requisições POST e PUT.
  Ex: { "nome": "Lucas", "idade": 25 }

=============================================
 Explicação dos Principais HTTP Status Codes
=============================================

- 200 OK:             Requisição bem-sucedida (resposta padrão para sucesso)
- 201 Created:        Recurso criado com sucesso (POST)
- 204 No Content:     Requisição bem-sucedida, mas sem corpo de resposta (DELETE)
- 400 Bad Request:    Requisição malformada ou dados inválidos
- 404 Not Found:      Recurso não encontrado
- 500 Internal Error: Erro interno no servidor

=====================================
 MongoDB
=====================================

- O MongoDB é um banco de dados NoSQL orientado a documentos.
- Ele armazena dados em formato JSON, permitindo flexibilidade e escalabilidade.
- Usuário: williamdossantosrodrigues94
- Senha: Willis@123

=====================================
 Rotas da Aplicação
=====================================
*/

// [POST] Criar um novo usuário
app.post("/usuarios", (req, res) => {
  console.log(req.body);
  usuarios.push(req.body);
  res.status(201).json(req.body);
});

// [GET] Listar todos os usuários
app.get("/usuarios", (req, res) => {
  res.status(200).json(usuarios);
});

// Inicializando o servidor
app.listen(3000, () => {
  console.log("Servidor rodando na porta 3000 com sucesso!");
  console.log("Acesse: http://localhost:3000/usuarios");
});
