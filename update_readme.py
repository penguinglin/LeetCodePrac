import re

def update_readme(input_file, output_file):
    # 定義關鍵字與對應的超連結
    replacements = {
        r'\bEasy\b': '[Easy](/EASY/)',  # \b 確保是獨立單詞
        r'\bMedium\b': '[Medium](/Medium/)',
        r'\bHard\b': '[Hard](/Hard/)'
    }

    # 讀取 README 文件
    with open(input_file, 'r', encoding='utf-8') as f:
        content = f.read()

    # 替換關鍵字為超連結，但略過已經有超連結的情況
    for pattern, replacement in replacements.items():
        content = re.sub(
            fr'(?<!\[){pattern}(?!\])',  # 略過已經在 [...] 中的單詞
            replacement,
            content
        )

    # 將更新後的內容寫入到新的文件
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)

    print(f"Updated README saved to {output_file}")

# 使用方式
if __name__ == '__main__':
    input_readme = 'README.md'
    output_readme = 'README.md'  # 覆蓋原始文件
    update_readme(input_readme, output_readme)
