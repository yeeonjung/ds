from __future__ import annotations

def main() -> None:
    try:
        dan_input = input("몇 단? ")
        dan = int(dan_input.strip())
    except ValueError:
        print("숫자를 입력해주세요.")
        return

    if dan < 1 or dan > 9:
        print("1에서 9 사이의 단을 입력해주세요.")
        return

    for i in range(1, 10):
        print(f"{dan} x {i} = {dan * i}")


if __name__ == "__main__":
    main()
