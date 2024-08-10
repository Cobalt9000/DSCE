FROM python:3.9
RUN pip install scikit-learn streamlit
WORKDIR /app
COPY scripts/ /app/scripts
WORKDIR /app/scripts
EXPOSE 8501
CMD ["streamlit", "run", "app.py"]