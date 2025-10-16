# GitLab: Мануал по работе с репозиторием

## 1. Создание личного репозитория с .gitignore и README.md

1. Перейдите в GitLab и зайди в свой аккаунт: [https://gitlab.com](https://gitlab.com).
2. Нажмите "New Project".
3. Нажмите "Create blank project"
4. Укажите:

   * Project name — имя проекта.
   * Visibility level — чаще всего Private.
   * Отметьте:

     * ☑️ Initialize repository with a README

![Скриншот](<img/Screenshot 2025-07-22 at 2.31.21 PM.png>)
📷 *Настройки при создании проекта*

---

## 2. Создание веток develop и master

1. После создания репозитория перейдите в Repository → Branches.
2. Нажмите "New branch":

   * Введите develop, создайте из main (или master, если он уже есть).
3. Вводим желаемое имя ветки и укзываем от какой ветки мы создаем новую ветку в поле "Create From"

![Скриншот](<img/Screenshot 2025-07-22 at 2.44.14 PM.png>)
📷 *Создание новой ветки*

---

## 3. Установка ветки develop по умолчанию

1. Перейдите в Settings → Repository → Default Branch.
2. Выберите develop и нажмите "Save changes".

![Скриншот](<img/Screenshot 2025-07-22 at 2.50.12 PM.png>)
📷 *Установка ветки по умолчанию*

---

## 4. Создание issue на написание текущего мануала

1. Перейдите в Issues → New Issue.
2. Введите название.
3. Составьте опиание 
4. Назначьте себя и сохраните Create Issue.

![Скриншот](<img/Screenshot 2025-07-22 at 2.54.16 PM.png>)
📷 *Создание нового issue*

---

## 5. Создание ветки по issue

1. На странице issue нажмите "Create merge request" → Create branch".
2. Вводим название ветки
3. Ветка создается из develop.


## 🔀 6. Создание merge request в develop

1. После пуша изменений, нажмите "Create merge request".
2. Убедитесь, что:

   * Проверь те ли данные введены в Source branch и Target branch:

![Скриншот](<img/Screenshot 2025-07-22 at 3.00.11 PM.png>)
📷 *Создание Merge Request*

---

## 7. Комментирование и принятие Merge Request

1. Другие участники могут оставить комментарии в Activity.
2. После одобрения нажмите "Merge".

![Скриншот](<img/Screenshot 2025-07-22 at 3.05.33 PM.png>)
📷 *Комментарии и Merge*

---

## 8. Формирование стабильной версии в master с тегом

1. Перейдите в Repository → Tags
2. Нажмите "New tag"
3. Заполните информацию и название

![Скриншот](<img/Screenshot 2025-07-22 at 3.07.32 PM.png>)
📷 *Создание тега*

---

## 9. Работа с Wiki проекта

Используя Markdown создается удобная форма хранения документации о проекте 

